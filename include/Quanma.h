#ifndef QUANMA_H
#define QUANMA_H
#include "Quanco.h"
class Quanma : public Quanco {
public:
	Quanma(){};
	~Quanma(){};
	Quanma(std::string name, bool phe, bool trangthai, int x, int y) {
		this->setname(name);
		this->setphe(phe);
		// this->settrangthai(trangthai);
		this->setx(x);
		this->sety(y);
	}

  	void cacnuocdichuyen(std::string banco[8][8]) {
		if(this->getx() - 1 >= 0 && this->gety() - 2 >= 0 && banco[this->getx() - 1][this->gety() - 2] == "--")
			banco[this->getx() - 1][this->gety() - 2] = " x";
		if(this->getx() - 1 >= 0 && this->gety() + 2 < 8 && banco[this->getx() - 1][this->gety() + 2] == "--")
			banco[this->getx() - 1][this->gety() + 2] = " x";
		
		if(this->getx() + 1 < 8 && this->gety() - 2 >= 0 && banco[this->getx() + 1][this->gety() - 2] == "--")
			banco[this->getx() + 1][this->gety() - 2] = " x";
		if(this->getx() + 1 < 8 && this->gety() + 2 < 8 && banco[this->getx() + 1][this->gety() + 2] == "--")
			banco[this->getx() + 1][this->gety() + 2] = " x";
		
		if(this->getx() - 2 >= 0 && this->gety() - 1 >= 0 && banco[this->getx() - 2][this->gety() - 1] == "--")
			banco[this->getx() - 2][this->gety() - 1] = " x";
		if(this->getx() - 2 >= 0 && this->gety() + 1 < 8 && banco[this->getx() - 2][this->gety() + 1] == "--")
			banco[this->getx() - 2][this->gety() + 1] = " x";

		if(this->getx() + 2 < 8 && this->gety() - 1 >= 0 && banco[this->getx() + 2][this->gety() - 1] == "--")
			banco[this->getx() + 2][this->gety() - 1] = " x";
		if(this->getx() + 2 < 8 && this->gety() + 1 < 8 && banco[this->getx() + 2][this->gety() + 1] == "--")
			banco[this->getx() + 2][this->gety() + 1] = " x";
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

		//---------------------------------------------------------------------------------------------//
		
		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() - 1 && this->getx() - 1 >= 0) && (y == this->gety() - 2 && this->gety() - 2 >= 0)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() - 1 && this->getx() - 1 >= 0) && (y == this->gety() + 2 && this->gety() + 2 < 8)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() + 1 && this->getx() + 1 < 8) && (y == this->gety() - 2 && this->gety() - 2 >= 0)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() + 1 && this->getx() + 1 < 8) && (y == this->gety() + 2 && this->gety() + 2 < 8)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() - 2 && this->getx() - 2 >= 0) && (y == this->gety() - 1 && this->gety() - 1 >= 0)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() - 2 && this->getx() - 2 >= 0) && (y == this->gety() + 1 && this->gety() + 1 < 8)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() + 2 && this->getx() + 2 < 8) && (y == this->gety() - 1 && this->gety() - 1 >= 0)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		else if(banco[x][y].find(phe) == std::string::npos && (x == this->getx() + 2 && this->getx() + 2 < 8) && (y == this->gety() + 1 && this->gety() + 1 < 8)){
			this->setx(x);
			this->sety(y);
			this->change();
			banco[x][y] = this->getname();
			banco[_x][_y] = "--";
        }

		//---------------------------------------------------------------------------------------//

		else{
			std::cout << "error di chuyen ma\n\n";
			this->undo(banco);
			return false;
		}
		this->undo(banco);
		return true;
	}
};
#endif