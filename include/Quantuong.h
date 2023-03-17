#ifndef QUANTUONG_H
#define QUANTUONG_H
#include "Quanco.h"
class Quantuong:public Quanco{
    public:
        Quantuong(){};
        ~Quantuong(){};
        Quantuong(std::string name, bool phe, bool trangthai, int x, int y) {
            this->setname(name);
            this->setphe(phe);
            // this->settrangthai(trangthai);
            this->setx(x);
            this->sety(y);
        }

        int block[4][2] ={{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
        
        void cacnuocdichuyen(std::string banco[8][8]){
            int x = this->getx() + 1;
            int y = this->gety() + 1;
            int _x = this->getx() - 1;
            int _y = this->gety() - 1;

            while(x < 8 && y < 8){
                if(banco[x][y] == "--"){
                    banco[x][y] = " x";
                    x += 1;
                    y += 1;
                }
                else{
                    block[0][0] = x;
                    block[0][1] = y;   
                    break;
                }
            }

            x = this->getx() + 1;
            y = this->gety() + 1;
            _x = this->getx() - 1;
            _y = this->gety() - 1;
            while(_x >= 0 && y < 8){
                if(banco[_x][y] == "--"){
                    banco[_x][y] = " x";
                    _x -= 1;
                    y += 1;
                }
                else{
                    block[1][0] = _x;
                    block[1][1] = y;
                    break;
                }
            }

            x = this->getx() + 1;
            y = this->gety() + 1;
            _x = this->getx() - 1;
            _y = this->gety() - 1;
            while(x < 8 && _y >= 0){
                if(banco[x][_y] == "--"){
                    banco[x][_y] = " x";
                    x += 1;
                    _y -= 1;
                }
                else{
                    block[2][0] = x;
                    block[2][1] = _y;
                    break;
                }
            }

            x = this->getx() + 1;
            y = this->gety() + 1;
            _x = this->getx() - 1;
            _y = this->gety() - 1;
            while(_x >= 0 && _y >= 0){
                if(banco[_x][_y] == "--"){
                    banco[_x][_y] = " x";
                    _x -= 1;
                    _y -= 1;
                }
                else{
                    block[3][0] = _x;
                    block[3][1] = _y;
                    break;
                }
            }
        }
        
        bool dichuyen(std::string banco[8][8], int x, int y){
            std::string phe;
            if(this->getname().find("W") != std::string::npos)
                phe = "W";
            else    
                phe = "B";

            int _x = this->getx();
            int _y = this->gety();
            if(banco[x][y] == " x"){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }
            
            //-----------------------------------------------------------------------------//

            else if(banco[x][y].find(phe) == std::string::npos && x == block[0][0] && y == block[0][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            else if(banco[x][y].find(phe) == std::string::npos && x == block[1][0] && y == block[1][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            else if(banco[x][y].find(phe) == std::string::npos && x == block[2][0] && y == block[2][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            else if(banco[x][y].find(phe) == std::string::npos && x == block[3][0] && y == block[3][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            //--------------------------------------------------------------------------//
                  
            else{
                std::cout << "error di chuyen tuong" << std::endl << std::endl;
                this->undo(banco);
                return false;
            }
            this->undo(banco);
            return true;
        }
};
#endif