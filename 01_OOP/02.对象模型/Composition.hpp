//
// Created by fzy on 23-10-12.
//

#ifndef CLASSMODELTEST_COMPOSITION_HPP
#define CLASSMODELTEST_COMPOSITION_HPP

/** 组合关系下的对象模型 */
#include <iostream>
#include <string>
#include <vector>

class Engine {
public:
    Engine()
    : m_torque(200),
      m_brand("SAIC")
  {}
    void start() {
        std::cout << "Engine started." << std::endl;
    }

    void stop() {
        std::cout << "Engine stopped." << std::endl;
    }
public:
    int m_torque;
    std::string m_brand;
};

class Car {
public:
    std::string m_brand;
    std::string m_model;
    Engine m_engine;
public:
    Car(const std::string& make, const std::string& model) : m_brand(make), m_model(model) {}

    void start() {
        std::cout << "Starting the car: " << m_brand << " " << m_model << std::endl;
        m_engine.start();
    }

    void stop() {
        std::cout << "Stopping the car: " << m_brand << " " << m_model << std::endl;
        m_engine.stop();
    }
};


#endif //CLASSMODELTEST_COMPOSITION_HPP
