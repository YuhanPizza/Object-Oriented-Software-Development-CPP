/*
*****************************************************************************
            Milestone - #3
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "LineManager.h"
#include <fstream>
#include <algorithm>
#include "Utilities.h"
using namespace std;

namespace sdds {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        std::ifstream ifs(file);
        if (!ifs) {
            throw std::string("Unable to open [") + file + "] file.";
        }
        size_t nxt_pos = 0u;
        bool more = false;
        Utilities util;
        std::string record;
        while (std::getline(ifs, record)) {
            if (!record.empty()) {
                nxt_pos = 0;

                std::string station = util.extractToken(record, nxt_pos, more);
                std::string nxt_station = "a";
                if (more) {
                    nxt_station = util.extractToken(record, nxt_pos, more);
                }
                Workstation* curr = nullptr;
                Workstation* nxt = nullptr;

                auto currIt = std::find_if(stations.begin(), stations.end(), [&](const auto& ptr) {
                    return ptr->getItemName() == station;
                    });

                if (currIt != stations.end()) curr = *currIt;

                auto nxtIt = std::find_if(stations.begin(), stations.end(), [&](const auto& ptr) {
                    return ptr->getItemName() == nxt_station;
                    });
                if (nxtIt != stations.end()) nxt = *nxtIt;

                if (curr && nxt) {
                    curr->setNextStation(nxt);
                    m_activeLine.push_back(curr);
                }
                else {
                    m_activeLine.push_back(curr);
                }
            }
        }
        ifs.close();

        m_firstStation = nullptr;
        for (auto& station : stations) {
            auto check  = [&stations, &station]() {
                return std::any_of(stations.begin(), stations.end(), [&station](const auto& check_station_ptr) {
                    return check_station_ptr->getNextStation() == station;
                });
            };
            if (!check()) {
                m_firstStation = station;
            }
        }
        if (!m_firstStation) {
            throw std::string("Unable to find the first station in the assembly line.");
        }
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations(){
        std::vector<Workstation*> station;
        for (auto ptr = m_firstStation; ptr != nullptr; ptr = ptr->getNextStation()) {
            station.push_back(ptr);
        }
        m_activeLine = station;
    }

    bool LineManager::run(std::ostream& os){
        static size_t count = 0u;
        os << "Line Manager Iteration: " << ++count << endl;
        if (!g_pending.empty()) {
            *m_activeLine.front() += move(g_pending.front());
            g_pending.pop_front();
        }

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto& src) {
            src->fill(os);
            });
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto& src) {
            src->attemptToMoveOrder();
            });

        return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
    }

    void LineManager::display(std::ostream& os) const{
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* src) {
            src->display(os);
        });
    }
}