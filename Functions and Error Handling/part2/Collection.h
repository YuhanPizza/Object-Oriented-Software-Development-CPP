/*
*****************************************************************************
            Workshop - #5
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>

namespace sdds {
    //templated class
    template <typename T>
    class Collection {
        std::string c_name {""}; //the name of the collection;
        T* c_items{ nullptr }; //a dynamically allocated array of items T
        size_t c_size{ 0u }; //the size of the array
//returns void //a pointer to a function    //recieves 2 parameters const Collection<T>& and const T&
        void (*c_observer)(const Collection<T>&, const T&){ nullptr }; //explain in reflection?

    public:
        //constructor with parameters
        Collection(const std::string& name) : c_name(name){} // Sets the name of the collection to the string referred to by the 
        //parameter besides that does nothing since other attributes are already in default value

        //copy constructor and assignment
        Collection(const Collection<T>&) = delete; //deleted copy constructor
        Collection<T>& operator=(const Collection<T>&) = delete; //deleted all assignment operators

        //destructors
        ~Collection() { //destructor if c_items exist delete it 
            if (c_items) {
                delete[] c_items;
            }
        }


        //query
        const std::string& name() const { //returns name
            return c_name;
        }

        size_t size() const { //returns size 
            return c_size;
        }
                             
        void setObserver(void (*observer)(const Collection<T>&, const T&)) { //explain in reflection? sets the pointer of a function to point to a function basically
            //making it point to the argument so whatever function is passed as setObserver the c_observer will point to them
            c_observer = observer;
        }

        Collection<T>& operator+=(const T& item) {
            for (size_t i = 0; i < c_size; i++) {
                if (c_items[i].title() == item.title()) { //if the item title already exist inside of the collection
                    return *this; //do nothing
                }
            }

            T* temp = new T[c_size + 1]; //create a temporary object array with the increased size 
            for (size_t i = 0; i < c_size; i++) { //loop to
                temp[i] = c_items[i]; //assign all the values for c_items to temp 
            }
            temp[c_size] = item; //store the added item into the last index of the temporary array
            delete[] c_items; //delete c_items
            c_items = nullptr; //set to null
            c_size++;
            c_items = temp; //assign the values

            if (c_observer ) { //if c_observer is not null then call the function that is why 5th 6th and 7th book are in the display
                c_observer(*this, item);//c_observer function call
            }

            return *this;
        }

        T& operator[](size_t idx) const {
            if (idx >= c_size) { //if index is larger or equal to the c_size
                //std::string potato = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.";
                //throw std::out_of_range(potato);
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");
            }
            return c_items[idx]; //else return the item in that index
        }

        T* operator[](const std::string& title) const { //takes in a string parameter
            for (size_t i = 0; i < c_size; i++) { //loops through all the items
                if (c_items[i].title() == title) { //if an item matches the string 
                    return &c_items[i]; //return the index of the item that has the same title as the string
                }
            }
            return nullptr; 
        }
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& src) { //display function calls the display of either Movie or Book.
        for (size_t i = 0; i < src.size(); i++) {
            os << src[i]; //calls the overloaded extraction operator of the object passed in as argument
        }
        return os;
    }
}
#endif
