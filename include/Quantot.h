#ifndef QUANTOT_H
#define QUANTOT_H
#include "Quanco.h"
class Quantot : public Quanco {
  public:
    Quantot(){};
    ~Quantot(){};
    Quantot(std::string name, bool phe, bool trangthai, int x, int y) {
      this->setname(name);
      this->setphe(phe);
      // this->settrangthai(trangthai);
      this->setx(x);
      this->sety(y);
    }

    void cacnuocdichuyen(std::string banco[8][8]) {
      if (this->getx() == 6 && this->getname() == "pW" && banco[this->getx() - 1][this->gety()] == "--" && banco[this->getx() - 2][this->gety()] == "--") {
        banco[this->getx() - 1][this->gety()] = " x";
        banco[this->getx() - 2][this->gety()] = " x";
      } else if (this->getx() == 1 && this->getname() == "pB" && banco[this->getx() + 1][this->gety()] == "--" && banco[this->getx() + 2][this->gety()] == "--") {
        banco[this->getx() + 1][this->gety()] = " x";
        banco[this->getx() + 2][this->gety()] = " x";
      } else if (this->getname() == "pW" && banco[this->getx() - 1][this->gety()] == "--") {
        banco[this->getx() - 1][this->gety()] = " x";
      } else if (this->getname() == "pB" && banco[this->getx() + 1][this->gety()] == "--") {
        banco[this->getx() + 1][this->gety()] = " x";
      }
    }

    bool dichuyen(std::string banco[8][8], int x, int y) {
      int _x = this->getx();
      int _y = this->gety();
      if (this->getx() == 6 && this->getname() == "pW" && _x - x < 3 && y == _y && banco[x][y] == " x") {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pW";
        banco[_x][_y] = "--";
        this->change();
      } else if (this->getx() == 1 && this->getname() == "pB" && x - _x < 3 && y == _y && banco[x][y] == " x") {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pB";
        banco[_x][_y] = "--";
        this->change();
      } else if (this->getname() == "pW" && _x - x < 2 && y == _y && banco[x][y] == " x") {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pW";
        banco[_x][_y] = "--";
        this->change();
      } else if (this->getname() == "pB" && x - _x < 2 && y == _y && banco[x][y] == " x") {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pB";
        banco[_x][_y] = "--";
        this->change();
      }

      //--------------------------------------------------------------------------------//

      else if (_y > 0 && _y < 7 && this->getname() == "pW" && banco[x][y] != "--" && banco[x][y].find("W") == std::string::npos && (x == _x - 1 && y == _y + 1 || x == _x - 1 && y == _y - 1)) {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pW";
        banco[_x][_y] = "--";
        this->change();
      } else if (_y == 0 && this->getname() == "pW" && banco[x][y] != "--" && banco[x][y].find("W") == std::string::npos && x == _x - 1 && y == _y + 1) {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pW";
        banco[_x][_y] = "--";
        this->change();
      } else if (_y == 7 && this->getname() == "pW" && banco[x][y] != "--" && banco[x][y].find("W") == std::string::npos && x == _x - 1 && y == _y - 1) {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pW";
        banco[_x][_y] = "--";
        this->change();
      }

      else if (_y > 0 && _y < 7 && this->getname() == "pB" && banco[x][y] != "--" && banco[x][y].find("B") == std::string::npos && (x == _x + 1 && y == _y + 1 || x == _x + 1 && y == _y - 1)) {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pB";
        banco[_x][_y] = "--";
        this->change();
      } else if (_y == 0 && this->getname() == "pB" && banco[x][y] != "--" && banco[x][y].find("B") == std::string::npos && x == _x + 1 && y == _y + 1) {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pB";
        banco[_x][_y] = "--";
        this->change();
      } else if (_y == 7 && this->getname() == "pB" && banco[x][y] != "--" && banco[x][y].find("B") == std::string::npos && x == _x + 1 && y == _y - 1) {
        this->setx(x);
        this->sety(y);
        banco[x][y] = "pB";
        banco[_x][_y] = "--";
        this->change();
      }

      //---------------------------------------------------------------------------------//

      else{
        std::cout << "error di chuyen tot\n\n";
        this->undo(banco);
        return false;
      }
      this->undo(banco);
      return true;
    }
};
#endif