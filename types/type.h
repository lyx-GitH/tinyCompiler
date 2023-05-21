//
// Created by 刘宇轩 on 2023/5/20.
//

#ifndef TINYCOMPILER_TYPE_H
#define TINYCOMPILER_TYPE_H

#include <string>
#include <utility>

struct my_struct {
    int a,b, :10;
    int x;

};

class Type {
public:
    Type(std::string  name, const std::size_t size) : name_(std::move(name)), size_(size) {}

    [[nodiscard]] const std::string &getName() const;

    void setName(const std::string &name);

    [[nodiscard]] size_t getSize() const;

protected:
    std::string name_;
    const std::size_t size_;
};


class PtrType : public Type {
public:
    PtrType(std::string name) : Type(std::move(name), sizeof(char*)) {}
private:
    std::unique_ptr<Type> TypePtrTo;
};

class ArrType : public Type {
public:

};


#endif //TINYCOMPILER_TYPE_H
