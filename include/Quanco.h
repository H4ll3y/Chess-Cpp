#ifndef QUANCO_H
#define QUANCO_H
#include <bits/stdc++.h>
class Quanco {
  private:
    std::string name;
    bool phe;
    // bool trangthai;
    int x;
    int y;

  public:
    void setname(std::string name) { this->name = name; }
    std::string getname() { return this->name; }
    void setphe(bool phe) { this->phe = phe; }
    bool getphe() { return this->phe; }
    // void settrangthai(bool trangthai) { this->trangthai = trangthai; }
    // bool gettrangthai() { return this->trangthai; }
    void setx(int x) { this->x = x; }
    int getx() { return this->x; }
    void sety(int y) { this->y = y; }
    int gety() { return this->y; }

    virtual void cacnuocdichuyen(std::string banco[8][8]) {
      
    }
    void undo(std::string banco[8][8]) {
      for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
          if (banco[i][j] == " x")
            banco[i][j] = "--";
    }
    virtual bool dichuyen(std::string banco[8][8], int x, int y) {}
    void change(){
      std::string y;
      if(this->gety() == 0) y = "A";
      else if(this->gety() == 1) y = "B";
      else if(this->gety() == 2) y = "C";
      else if(this->gety() == 3) y = "D";
      else if(this->gety() == 4) y = "E";
      else if(this->gety() == 5) y = "F";
      else if(this->gety() == 6) y = "G";
      else if(this->gety() == 7) y = "H";

      int x;
      switch (this->getx())
      {
        case 7: 
          x = 1; 
          break;
        case 6: 
          x = 2;
          break;
        case 5:
          x = 3;
          break;
        case 4:
          x = 4;
          break;
        case 3:
          x = 5;
          break;
        case 2:
          x = 6;
          break;
        case 1:
          x = 7;
          break;
        case 0:
          x = 8;
          break;
        default:
          break;
      }
      
      std::string phe;
      std::string next;
      if(this->phe){
        phe = "quan trang: ";
        next = "quan den B";
      }
      else{
        phe = "quan den: ";
        next = "quan trang W";
      }
      std::cout << phe << this->getname() << " di chuyen den " << x << " " << y << "\n\ntiep theo den " << next << "\n\n";
    }
};
#endif