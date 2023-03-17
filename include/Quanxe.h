#ifndef QUANXE_H
#define QUANXE_H
#include "Quanco.h"
class Quanxe:public Quanco{
      public:
            Quanxe(){};
            ~Quanxe(){};
            Quanxe(std::string name, bool phe, bool trangthai, int x, int y) {
                  this->setname(name);
                  this->setphe(phe);
                  // this->settrangthai(trangthai);
                  this->setx(x);
                  this->sety(y);
            }

            int block[4] = {-1,-1,-1,-1};
            
            void cacnuocdichuyen(std::string banco[8][8]) {
                  int x = this->getx() + 1;
                  while(x < 8){
                        if(banco[x][this->gety()] == "--"){
                              banco[x][this->gety()] = " x";
                              x += 1;
                        }
                        else{
                              block[0] = x;
                              break;
                        }
                  }
                  int _x = this->getx() - 1;
                  while(_x >= 0){
                        if(banco[_x][this->gety()] == "--"){
                              banco[_x][this->gety()] = " x";
                              _x -= 1;
                        }
                        else{
                              block[1] = _x;
                              break;
                        }
                  }

                  int y = this->gety() + 1;
                  while(y < 8){
                        if(banco[this->getx()][y] == "--"){
                              banco[this->getx()][y] = " x";
                              y += 1;
                        }
                        else{
                              block[2] = y;
                              break;
                        }
                  }
                  int _y = this->gety() - 1;
                  while(_y >= 0){
                        if(banco[this->getx()][_y]=="--"){
                              banco[this->getx()][_y] = " x";
                              _y -= 1;
                        }
                        else{
                              block[3] = _y;
                              break;
                        }
                  }

                  std::cout<<block[0]<<block[1]<<block[2]<<block[3]<<std::endl;
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

                  else if(block[0] >= 0 && banco[block[0]][y].find(phe) == std::string::npos && x == block[0] && y == this->gety()){
                        this->setx(x);
                        this->sety(y);
                        this->change();
                        banco[x][y] = this->getname();
                        banco[_x][_y] = "--";
                  }
                  else if(block[1] >= 0 &&banco[block[1]][y].find(phe) == std::string::npos && x == block[1] && y == this->gety()){
                        this->setx(x);
                        this->sety(y);
                        this->change();
                        banco[x][y] = this->getname();
                        banco[_x][_y] = "--";
                  }
                  else if(block[2] >= 0 &&banco[x][block[2]].find(phe) == std::string::npos && x == this->getx() && y == block[2]){
                        this->setx(x);
                        this->sety(y);
                        this->change();
                        banco[x][y] = this->getname();
                        banco[_x][_y] = "--";
                  }
                  else if(block[3] >= 0 && banco[x][block[3]].find(phe) == std::string::npos && x == this->getx() && y == block[3]){
                        this->setx(x);
                        this->sety(y);
                        this->change();
                        banco[x][y] = this->getname();
                        banco[_x][_y] = "--";
                  }

                  //--------------------------------------------------------------------------//
                  
                  else{
                        std::cout << "error di chuyen xe" << std::endl << std::endl;
                        this->undo(banco);
                        return false;
                  }
                  this->undo(banco);
                  return true;
            }
};
#endif