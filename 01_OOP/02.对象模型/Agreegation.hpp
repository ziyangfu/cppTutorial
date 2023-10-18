//
// Created by fzy on 23-10-13.
//

#ifndef CLASSMODELTEST_AGREEGATION_HPP
#define CLASSMODELTEST_AGREEGATION_HPP

/** 委托关系下的对象模型 */
/** 组合关系下的对象模型 */
#include <iostream>
#include <string>
#include <vector>

class Engine02 {
public:
    Engine02()
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

class Car02 {
public:
    std::string m_brand;
    std::string m_model;
    Engine02* m_engine;  /** 委托关系 */
public:
    Car02(const std::string& make, const std::string& model) : m_brand(make), m_model(model) {}

    void start() {
        std::cout << "Starting the car: " << m_brand << " " << m_model << std::endl;
        m_engine->start();
    }

    void stop() {
        std::cout << "Stopping the car: " << m_brand << " " << m_model << std::endl;
        m_engine->stop();
    }
};

#endif //CLASSMODELTEST_AGREEGATION_HPP
