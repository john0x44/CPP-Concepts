/*
	Name: TestPrototype
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing prototypes
*/
#include <iostream>

// Declare Box abstract base class 
class Box {
public:
    virtual void display() = 0;
    virtual Box* clone() = 0;
};

// Declare concrete implementations for Box
class WoodenBox : public Box {
public:
    void display() override {
        std::cout << "This is a wooden box.\n";
    }

    Box* clone() override {
        return new WoodenBox(*this);
    }
};

class MetalBox : public Box {
public:
    void display() override {
        std::cout << "This is a metal box.\n";
    }

    Box* clone() override {
        return new MetalBox(*this);
    }
};

// Box factory class
class BoxFactory {
public:
    static Box* createBox(const std::string& boxType) {
        if (boxType == "wooden") {
            return new WoodenBox();
        } else if (boxType == "metal") {
            return new MetalBox();
        } else {
            return nullptr; 
        }
    }
};

// Main test driver
int main() {
    // Create the box 
    Box* woodenBox = BoxFactory::createBox("wooden");
    Box* metalBox = BoxFactory::createBox("metal");
    woodenBox->display();
    metalBox->display();
    Box* clonedWoodenBox = woodenBox->clone();
    Box* clonedMetalBox = metalBox->clone();
    clonedWoodenBox->display();
    clonedMetalBox->display();
    delete woodenBox;
    delete metalBox;
    delete clonedWoodenBox;
    delete clonedMetalBox;
    return 0;
}