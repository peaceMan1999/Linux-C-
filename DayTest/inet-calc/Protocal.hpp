#pragma once

#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>

using namespace std;

// 请求格式
typedef struct request{
    int x;
    int y;
    char op;    // "+-*/%"
}request_t;

// 响应格式
typedef struct respone{
    int code;   // 结果
    int result; // 区分计算结果
}respone_t;


string RequestSerialization(const request_t& req){
    Json::Value root;
    root["x"] = req.x;
    root["y"] = req.y;
    root["op"] = req.op;

    Json::FastWriter writer;
    string str = writer.write(root);
    return str;
}

string ResponeSerialization(const respone_t& resp){
    Json::Value root;
    root["code"] = resp.code;
    root["result"] = resp.result;

    Json::FastWriter writer;
    string str = writer.write(root);
    return str;
}

void RequestDeserialization(request_t& req, const string& out){
    Json::Value root;
    Json::Reader reader;
    reader.parse(out, root);

    req.x = root["x"].asInt();
    req.y = root["y"].asInt();
    req.op = (char)root["op"].asInt();
}

void ResponeDeserialization(respone_t& resp, const string& out){
    Json::Value root;
    Json::Reader reader;
    reader.parse(out, root);

    resp.code = root["code"].asInt();
    resp.result = root["result"].asInt();
}



