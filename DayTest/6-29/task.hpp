#pragma once

#include <iostream>

class Task{
    private:
        int _x;
        int _y;
        char _op;
    public:
        Task(int x, int y, char op)
            :_x(x),
             _y(y),
             _op(op)
        {}
        Task(){}

        void Run()
        {
            int result = 0;
            switch(_op){
                case '+':
                    result = _x + _y;
                    break;
                case '-':
                    result = _x - _y;
                    break;
                case '*':
                    result = _x * _y;
                    break;
                case '/':
                    if (_y == 0){
                        std::cout << "/0 err" << std::endl;
                        result = -1;
                    }else{
                        result = _x / _y;
                    }
                    break;
                default:
                    break;
            }
            std::cout << _x << _op << _y << "=" << result << std::endl;
        }
        ~Task()
        {
        }

};
