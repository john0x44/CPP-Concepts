/*
	Name: TestAbstractFactory
	Copyright: 2023
	Author: John
	Date: 21/06/23 17:01
	Description: Implementing and testing a Factory design pattern
*/

#include <iostream>

// Declare Box abstract base class 
class Box {
public:
    virtual void display() = 0;
};

// Declare concrete implementations for Box
class WoodenBox : public Box {
public:
    void display() override {
        std::cout << "This is a wooden box.\n";
    }
};

class MetalBox : public Box {
public:
    void display() override {
        std::cout << "This is a metal box.\n";
    }
};

// Declare concrete implementations for Box
class LargerWoodenBox : public Box {
public:
    void display() override {
        std::cout << "This is a larger wooden box.\n";
    }
};

class LargerMetalBox : public Box {
public:
    void display() override {
        std::cout << "This is a larger metal box.\n";
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
            return nullptr; // Invalid box type
        }
    }
};

// LargerBox factory class
class LargerBoxFactory {
public:
    static Box* createBox(const std::string& boxType) {
        if (boxType == "wooden") {
            return new LargerWoodenBox();
        } else if (boxType == "metal") {
            return new LargerMetalBox();
        } else {
            return nullptr; // Invalid box type
        }
    }
};

// Main test driver
int main() {
    Box* woodenBox = BoxFactory::createBox("wooden");
    Box* metalBox = BoxFactory::createBox("metal");
    Box* largerWoodenBox = LargerBoxFactory::createBox("wooden");
    Box* largerMetalBox = LargerBoxFactory::createBox("metal");
	woodenBox->display();
    metalBox->display();
    largerWoodenBox->display();
    largerMetalBox->display();
    delete woodenBox;
    delete metalBox;
    delete largerWoodenBox;
    delete largerMetalBox;
    return 0;
}