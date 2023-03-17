#ifndef QUANVUA_H
#define QUANVUA_H
#include "Quanco.h"
class Quanvua:public Quanco{
    public:
        Quanvua(){};
        ~Quanvua(){};
        Quanvua(std::string name, bool phe, bool trangthai, int x, int y) {
            this->setname(name);
            this->setphe(phe);
            // this->settrangthai(trangthai);
            this->setx(x);
            this->sety(y);
        }

        int block1[4] = {-1,-1,-1,-1};
        int block2[4][2] ={{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};

        void cacnuocdichuyen(std::string banco[8][8]){
            int x = this->getx() + 1;
            int y = this->gety() + 1;
            int _x = this->getx() - 1;
            int _y = this->gety() - 1;

            if(x < 8 && y < 8){
                if(banco[x][y] == "--")
                    banco[x][y] = " x";
                else{
                    block2[0][0] = x;
                    block2[0][1] = y;   
                }
            }

            if(_x >= 0 && _y >= 0){
                if(banco[_x][_y] == "--")
                    banco[_x][_y] = " x";
                else{
                    block2[3][0] = _x;
                    block2[3][1] = _y;
                }
            }

            if(_x >= 0 && y < 8){
                if(banco[_x][y] == "--")
                    banco[_x][y] = " x";
                else{
                    block2[1][0] = _x;
                    block2[1][1] = y;
                }
            }

            if(x < 8 && _y >= 0){
                if(banco[x][_y] == "--")
                    banco[x][_y] = " x";
                else{
                    block2[2][0] = x;
                    block2[2][1] = _y;
                }
            }

            //-----------------------------------------------------------------------------------------//

            if(x < 8){
                if(banco[x][this->gety()] == "--")
                    banco[x][this->gety()] = " x";
                else
                    block1[0] = x;
            }

            if(x >= 0){
                if(banco[_x][this->gety()] == "--")
                    banco[_x][this->gety()] = " x";
                else
                    block1[1] = _x;
            }

            if(y < 8){
                if(banco[this->getx()][y] == "--")
                    banco[this->getx()][y] = " x";
                else
                    block1[2] = y;
            }

            if(_y >= 0){
                if(banco[this->getx()][_y]=="--")
                    banco[this->getx()][_y] = " x";
                else
                    block1[3] = _y;
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

            else if(banco[x][y].find(phe) == std::string::npos && x == block2[0][0] && y == block2[0][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            else if(banco[x][y].find(phe) == std::string::npos && x == block2[1][0] && y == block2[1][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            else if(banco[x][y].find(phe) == std::string::npos && x == block2[2][0] && y == block2[2][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            else if(banco[x][y].find(phe) == std::string::npos && x == block2[3][0] && y == block2[3][1]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            //-----------------------------------------------------------------------------//

            else if(block1[0] >= 0 && banco[block1[0]][y].find(phe) == std::string::npos && x == block1[0] && y == this->gety()){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }
            else if(block1[1] >= 0 && banco[block1[1]][y].find(phe) == std::string::npos && x == block1[1] && y == this->gety()){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }
            else if(block1[2] >= 0 && banco[x][block1[2]].find(phe) == std::string::npos && x == this->getx() && y == block1[2]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }
            else if(block1[3] >= 0 && banco[x][block1[3]].find(phe) == std::string::npos && x == this->getx() && y == block1[3]){
                this->setx(x);
                this->sety(y);
                this->change();
                banco[x][y] = this->getname();
                banco[_x][_y] = "--";
            }

            //--------------------------------------------------------------------------//
            
            else{
                std::cout << "error di chuyen vua" << std::endl << std::endl;
                this->undo(banco);
                return false;
            }
            this->undo(banco);
            return true;
        }
};
#endif