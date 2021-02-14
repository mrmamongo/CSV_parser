//
// Created by lamp on 06.02.2021.
//

#ifndef PRODUCER_CONSUMER_HASHER_HPP
#define PRODUCER_CONSUMER_HASHER_HPP

#include <string>
#include <chrono>
#include <nlohmann/json.hpp>
#include <picosha2.hpp>
#include <thread>
#include <iostream>

const static std::string hash_end = "0000";
using json = nlohmann::json;
class hasher {
public:
    typedef std::pair<std::string, std::string> key_value_t;
    inline static json encode(const key_value_t &key_value) {
        std::string hash = "THIS IS THE EMPTY STRING";
        auto start = std::chrono::system_clock::now();
        for (size_t nonce = 0;
             hash.substr(hash.length() - hash_end.length()) != hash_end;
             ++nonce) {
            hash = picosha2::hash256_hex_string(std::string(key_value.first + key_value.second + std::to_string(nonce)));
        }
//        std::cout << std::this_thread::get_id();
        return json{
                {"value", std::string(key_value.first + " : " + key_value.second)},
                {"hash", hash},
                {"timestamp", std::chrono::nanoseconds(std::chrono::system_clock::now() - start).count()}
        };
    }
    hasher() = delete;
};


#endif //PRODUCER_CONSUMER_HASHER_HPP
