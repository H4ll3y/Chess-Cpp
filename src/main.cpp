#include "Quanco.h"
#include "Quanma.h"
#include "Quantot.h"
#include "Quanxe.h"
#include "Quantuong.h"
#include "Quanhau.h"
#include "Quanvua.h"
#include <bits/stdc++.h>

//-----------------------------------FUNC--------------------------------------//

void inbanco(std::string banco[8][8]) {
  std::cout << "    A    B    C    D    E    F    G    H\n";
  for (int i = 0; i < 8; i++) {
    std::cout << abs(i - 8) << "  ";
    for (int j = 0; j < 8; j++) {
      std::cout << banco[i][j];
      if(j == 7)
        std::cout << "  ";
      else
        std::cout << "   ";
    }
    std::cout << abs(i - 8);
    std::cout << "\n";
  }
  std::cout << "    A    B    C    D    E    F    G    H";
  std::cout << std::endl << std::endl;
}

int chuyenx(int x){
  switch (x)
  {
    case 1: 
      return 7;
    case 2: 
      return 6;
    case 3: 
      return 5;
    case 4: 
      return 4;
    case 5: 
      return 3;
    case 6: 
      return 2;
    case 7: 
      return 1;
    case 8: 
      return 0;
    default:
      return -1;
  }
}

int chuyeny(std::string y){
  if(y == "a" || y == "A") return 0;
  else if(y == "b" || y == "B") return 1;
  else if(y == "c" || y == "C") return 2;
  else if(y == "d" || y == "D") return 3;
  else if(y == "e" || y == "E") return 4;
  else if(y == "f" || y == "F") return 5;
  else if(y == "g" || y == "G") return 6;
  else if(y == "h" || y == "H") return 7;
  else
    return -1;
}

int checkking(std::string banco[8][8]){
  int b = 0;
  int w = 0;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(banco[i][j] == "iW")
        w++;
      else if(banco[i][j] == "iB")
        b++;
    }
  }
  if(w!=0 && b!=0)
    return 0;
  else if(b!=0 && w == 0)
    return -1;
  return 1;
}

void cleanscreen(){
  system("clear");
  //std::cout << "\033[2J\033[1;1H";
}

//-----------------------------------------------MAIN FUNC------------------------------------------//

int main() {
  //-----------------QUAN TOT----------------------//
  std::map<int, Quantot> qtw;
  qtw[0] = Quantot("pW", true, true, 6, 0);
  qtw[1] = Quantot("pW", true, true, 6, 1);
  qtw[2] = Quantot("pW", true, true, 6, 2);
  qtw[3] = Quantot("pW", true, true, 6, 3);
  qtw[4] = Quantot("pW", true, true, 6, 4);
  qtw[5] = Quantot("pW", true, true, 6, 5);
  qtw[6] = Quantot("pW", true, true, 6, 6);
  qtw[7] = Quantot("pW", true, true, 6, 7);

  std::map<int, Quantot> qtb;
  qtb[0] = Quantot("pB", false, true, 1, 0);
  qtb[1] = Quantot("pB", false, true, 1, 1);
  qtb[2] = Quantot("pB", false, true, 1, 2);
  qtb[3] = Quantot("pB", false, true, 1, 3);
  qtb[4] = Quantot("pB", false, true, 1, 4);
  qtb[5] = Quantot("pB", false, true, 1, 5);
  qtb[6] = Quantot("pB", false, true, 1, 6);
  qtb[7] = Quantot("pB", false, true, 1, 7);

  //-----------------QUAN XE----------------------//
  std::map<int, Quanxe> qxw;
  qxw[0] = Quanxe("rW", true, true, 7, 0);
  qxw[1] = Quanxe("rW", true, true, 7, 7);

  std::map<int, Quanxe> qxb;
  qxb[0] = Quanxe("rB", false, true, 0, 0);
  qxb[1] = Quanxe("rB", false, true, 0, 7);

  //-------------------QUAN MA-----------------------//
  std::map<int, Quanma> qmw;
  qmw[0] = Quanma("kW", true, true, 7, 1);
  qmw[1] = Quanma("kW", true, true, 7, 6);

  std::map<int, Quanma> qmb;
  qmb[0] = Quanma("kB", false, true, 0, 1);
  qmb[1] = Quanma("kB", false, true, 0, 6);

  //----------------QUAN TUONG---------------------------//
  std::map<int, Quantuong> qttw;
  qttw[0] = Quantuong("bW", true, true, 7, 2);
  qttw[1] = Quantuong("bW", true, true, 7, 5);

  std::map<int, Quantuong> qttb;
  qttb[0] = Quantuong("bB", false, true, 0, 2);
  qttb[1] = Quantuong("bB", false, true, 0, 5);

  //-------------------QUAN HAU---------------------------------//
  Quanhau qhw = Quanhau("qW", true, true, 7, 3);
  Quanhau qhb = Quanhau("qB", false, true, 0, 3);

  //-------------------QUAN VUA-----------------------------------//
  Quanvua qvw = Quanvua("iW", true, true, 7, 4);
  Quanvua qvb = Quanvua("iB", true, true, 0, 4);

  //--------------------------------------------------//
  int countp[2] = {0, 0};
  int countr[2] = {0, 0};
  int countk[2] = {0, 0};
  int countb[2] = {0, 0};

  //-------------------------------------------------------//
  std::string banco[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (qtb[countp[0]].getx() == i && qtb[countp[0]].gety() == j) {
        banco[i][j] = qtb[countp[0]].getname();
        countp[0]++;
      } else if (qtw[countp[1]].getx() == i && qtw[countp[1]].gety() == j) {
        banco[i][j] = qtw[countp[1]].getname();
        countp[1]++;
      } 
            
      //--------------------------------------------------------------------------//
      
      else if (qxb[countr[0]].getx() == i && qxb[countr[0]].gety() == j) {
        banco[i][j] = qxb[countr[0]].getname();
        countr[0]++;
      } else if (qxw[countr[1]].getx() == i && qxw[countr[1]].gety() == j) {
        banco[i][j] = qxw[countr[1]].getname();
        countr[1]++;
      } 
            
      //--------------------------------------------------------------------------//
      
      else if (qmb[countk[0]].getx() == i && qmb[countk[0]].gety() == j) {
        banco[i][j] = qmb[countk[0]].getname();
        countk[0]++;
      } else if (qmw[countk[1]].getx() == i && qmw[countk[1]].gety() == j) {
        banco[i][j] = qmw[countk[1]].getname();
        countk[1]++;
      } 

      //------------------------------------------------------------------------//

      else if (qttb[countb[0]].getx() == i && qttb[countb[0]].gety() == j) {
        banco[i][j] = qttb[countb[0]].getname();
        countb[0]++;
      } else if (qttw[countb[1]].getx() == i && qttw[countb[1]].gety() == j) {
        banco[i][j] = qttw[countb[1]].getname();
        countb[1]++;
      } 
      
      //--------------------------------------------------------------------------//

      else{
        banco[i][j] = "--";
        banco[qhw.getx()][qhw.gety()] = qhw.getname();
        banco[qhb.getx()][qhb.gety()] = qhb.getname();
        banco[qvw.getx()][qvw.gety()] = qvw.getname();
        banco[qvb.getx()][qvb.gety()] = qvb.getname();
      }
    }
  }

  cleanscreen();
  inbanco(banco);

  //--------------------------------------------------------------------------------//

  bool check = true;
  bool turn = true;
  while (check) {
    // inbanco(banco);
    int x_;
    std::string y_;
    std::cin >> x_;
    std::cin.ignore();
    getline (std::cin, y_);
    std::cout << "\n";
    int _x = chuyenx(x_), _y = chuyeny(y_);
    int _x_;
    std::string _y_;
    int x, y;
    int cur = 0;
    int _cur;
    if(_x == -1 || _y == -1){
      cleanscreen();
      std::cout << "error nhap vi tri" << std::endl << std::endl;
      inbanco(banco);
      continue;
    }

    //----------------------------WHITE---------------------------------------------//

    if (turn && banco[_x][_y].find("W") != std::string::npos) {
      for (int i = 0; i < 8; i++) {
        if (qtw[i].getx() == _x && qtw[i].gety() == _y) {
          cur = i;
          _cur = 1;
          break;
        } 

        //--------------------------------------------------------------------//
        else if ((i == 0 || i == 1) && qxw[i].getx() == _x && qxw[i].gety() == _y) {
          cur = i;
          _cur = 2;
          break;
        }
        
        //--------------------------------------------------------------------//
        else if ((i == 0 || i == 1) && qmw[i].getx() == _x && qmw[i].gety() == _y) {
          cur = i;
          _cur = 3;
          break;
        }

        //--------------------------------------------------------------------//
        else if ((i == 0 || i == 1) && qttw[i].getx() == _x && qttw[i].gety() == _y) {
          cur = i;
          _cur = 4;
          break;
        }

        //--------------------------------------------------------------------//
        _cur = 0;
      }

      if(qhw.getx() == _x && qhw.gety() == _y){
        _cur = 5;
      }

      else if(qvw.getx() == _x && qvw.gety() == _y){
        _cur = 6;
      }

      switch (_cur) {
        case 1:
          cleanscreen();
          qtw[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qtw[cur].dichuyen(banco, x, y))
            turn = false;
          inbanco(banco);
          break;
        case 2:
          cleanscreen();
          qxw[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qxw[cur].dichuyen(banco, x, y))
            turn = false;
          inbanco(banco);
          break;
        case 3:
          cleanscreen();
          qmw[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qmw[cur].dichuyen(banco, x, y))
            turn = false;
          inbanco(banco);
          break;
        case 4:
          cleanscreen();
          qttw[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qttw[cur].dichuyen(banco, x, y))
            turn = false;
          inbanco(banco);
          break;
        case 5:
          cleanscreen();
          qhw.cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qhw.dichuyen(banco, x, y))
            turn = false;
          inbanco(banco);
          break;
        case 6:
          cleanscreen();
          qvw.cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qvw.dichuyen(banco, x, y))
            turn = false;
          inbanco(banco);
          break;
        default:
          cleanscreen();
          std::cout << "error chon quan di chuyen" << std::endl << std::endl;
          inbanco(banco);
          continue;
      }
    }

    //----------------------------Black---------------------------------------------//

    else if (!turn && banco[_x][_y].find("B") != std::string::npos) {
      for (int i = 0; i < 8; i++) {
        if (qtb[i].getx() == _x && qtb[i].gety() == _y) {
          cur = i;
          _cur = 1;
          break;
        } 

        //--------------------------------------------------------------------//
        else if ((i == 0 || i == 1) && qxb[i].getx() == _x && qxb[i].gety() == _y) {
          cur = i;
          _cur = 2;
          break;
        }
        
        //--------------------------------------------------------------------//
        else if ((i == 0 || i == 1) && qmb[i].getx() == _x && qmb[i].gety() == _y) {
          cur = i;
          _cur = 3;
          break;
        }

        //--------------------------------------------------------------------//
        else if ((i == 0 || i == 1) && qttb[i].getx() == _x && qttb[i].gety() == _y) {
          cur = i;
          _cur = 4;
          break;
        }

        //--------------------------------------------------------------------//
        _cur = 0;
      }

      if(qhb.getx() == _x && qhb.gety() == _y){
        _cur = 5;
      }

      else if(qvb.getx() == _x && qvb.gety() == _y){
        _cur = 6;
      }

      switch (_cur) {
        case 1:
          cleanscreen();
          qtb[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qtb[cur].dichuyen(banco, x, y))
            turn = true;
          inbanco(banco);
          break;
        case 2:
          cleanscreen();
          qxb[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qxb[cur].dichuyen(banco, x, y))
            turn = true;
          inbanco(banco);
          break;
        case 3:
          cleanscreen();
          qmb[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qmb[cur].dichuyen(banco, x, y))
            turn = true;
          inbanco(banco);
          break;
        case 4:
          cleanscreen();
          qttb[cur].cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qttb[cur].dichuyen(banco, x, y))
            turn = true;
          inbanco(banco);
          break;
        case 5:
          cleanscreen();
          qhb.cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qhb.dichuyen(banco, x, y))
            turn = true;
          inbanco(banco);
          break;
        case 6:
          cleanscreen();
          qvb.cacnuocdichuyen(banco);
          inbanco(banco);
          std::cin >> _x_;
          x = chuyenx(_x_);
          std::cin.ignore();
          getline(std::cin, _y_);
          y = chuyeny(_y_);
          std::cout << "\n";
          cleanscreen();
          if(qvb.dichuyen(banco, x, y))
            turn = true;
          inbanco(banco);
          break;
        default:
          cleanscreen();
          std::cout << "error chon quan di chuyen" << std::endl << std::endl;
          inbanco(banco);
          continue;
      }
    }

    //-------------------------------ERROR------------------------------------------//

    else if (turn) {
      cleanscreen();
      std::cout << "luot W chon quan W" << std::endl << std::endl;
      inbanco(banco);
    } else {
      cleanscreen();
      std::cout << "luot B chon quan B" << std::endl << std::endl;
      inbanco(banco);
    }

    //----------------------CHECKING---------------------------------------//

    if(checkking(banco) == 0){
      check = true;
    }
    else if(checkking(banco) == -1){
      std::cout << "B win\n\n";
      check = false;
    }
    else if(checkking(banco) == 1){
      std::cout << "W win\n\n";
      check = false;
    }
  }
  return 0;
}