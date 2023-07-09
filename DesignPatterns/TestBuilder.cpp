/*
	Name: TestBuilder
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing builder pattern
*/
#include <iostream>
#include <string>
using namespace std;

class Box{
	private:
		string material;
		double size;
	public:
		Box(string materialType): material{materialType}{}
		void setMaterial(string thisMaterialType){material = thisMaterialType;}
		string getMaterial(){return material;}
		void setSize(double thisSize){size = thisSize;}
};

class BoxBuilder{
	protected:
		Box *box;
	public:
		virtual void buildMaterial() = 0;
		virtual void buildSize() = 0;
		Box* getBox(){return box;}
};

class smallBoxBuilder : public BoxBuilder{
	public:
		void buildMaterial(){box = new Box("wood");};
		void buildSize(){box->setSize(10.12);}
};

// Director will tell what to components to 'build'!
class Director{
	public:
		Box* createBox(BoxBuilder *builder){
			builder->buildMaterial();
			builder->buildSize();
			return builder->getBox();
		}
};

// Main test driver
int main(){
	Director dir;
	smallBoxBuilder smallBoxBuilder;
	Box *smallBox = dir.createBox(&smallBoxBuilder);
	cout << "The newly built box is made out of: " << smallBox->getMaterial() << endl;
	return 0;
};