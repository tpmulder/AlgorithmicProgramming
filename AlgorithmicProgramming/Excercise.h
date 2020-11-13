#pragma once
#ifndef EXCERSIZE_H
#define EXCERSIZE_H

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <functional>
#include <algorithm>
#include <sstream>

template<typename TItem, template<typename...> class Ref>
struct is_specialization : std::false_type {};

template<template<typename...> class Ref, typename... Args>
struct is_specialization<Ref<Args...>, Ref> : std::true_type {};

template <typename T>
class Excercise {
private:
    std::string name_;
    std::function<T()> fn_;
    std::string input_;

    template <typename TType>
    std::string display(const std::vector<TType>& vec) {
        std::stringstream result;
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<TType>(result, ", "));

        return result.str();
    }
public:
	Excercise(std::string& name, std::string& input, std::function<T()>& fn) {
        name_ = name;
        input_ = input;
        fn_ = fn;
	}

    T run() {
        return fn_();
    }

    std::string name() {
        return name_;
    }

    std::string input() {
        return input_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Excercise<T>& exc) {
        auto t1 = std::chrono::high_resolution_clock::now();
        os << exc.name_ << " with input: " << exc.input_ << " returned " << exc.run();
        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        os << " in " << duration << "ms" << std::endl;

        return os;
    }

    std::string to_string() {
        std::string str = name() + " with input: " + input() + " returned ";

        const auto t1 = std::chrono::high_resolution_clock::now();
        T ans = run();
        const auto t2 = std::chrono::high_resolution_clock::now();

        std::string cAns = "";

        cAns += display<int>(ans);

        //if (is_specialization<T, std::vector>::value) {
        //    try
        //    {
        //        cAns += display<int>(ans);
        //    }
        //    catch (const std::exception&)
        //    {
        //        cAns += display<std::string>(ans);
        //    }

        //} else {
        //    cAns = std::to_string(ans);
        //}

        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        return str += cAns + " in " + std::to_string(duration) + "ms";
    }
};

#endif // !EXCERSIZE_H