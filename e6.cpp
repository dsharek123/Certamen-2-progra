#include <iostream>
#include <stdlib.h>
#include <sstream>


class Student{
    private:
        int edad;
        std::string nombre;
        std::string apellido;
        int standard;
    public:
        void set_age(int a){
            edad = a;
        }
        void set_first_name(std::string b){
            nombre = b;
        }
        void set_last_name(std::string c){
            apellido = c;
        }
        void set_standard(int d){
            standard = d;
        }

        int get_age() { return edad; }
        std::string get_first_name() { return nombre; }
        std::string get_last_name() { return apellido; }
        int get_standard() { return standard; }
        
            std::string to_string(){
            std::stringstream ss;

            ss << edad << "," << nombre << "," << apellido << "," << standard;
            
            return ss.str(); 
        }

};
