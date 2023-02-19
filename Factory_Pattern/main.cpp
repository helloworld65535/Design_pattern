#include <iostream>

/*
 * 我们将创建一个 Shape 接口和实现 Shape 接口的实体类。下一步是定义工厂类 ShapeFactory。
 * FactoryPatternDemo 类使用 ShapeFactory 来获取 Shape 对象。
 * 它将向 ShapeFactory 传递信息（CIRCLE / RECTANGLE / SQUARE），以便获取它所需对象的类型。
 */

// 步骤 1 创建一个接口
class Shape
{
public:
    virtual void draw() = 0;
};

// 步骤 2 创建实现接口的实体类
class Circle : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "画一个圆" << std::endl;
    }
};

class Square : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "画一个正方形" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "画一个矩形" << std::endl;
    }
};

// 步骤 3 创建一个工厂，生成基于给定信息的实体类的对象。
class ShapeFactory
{
public:
    Shape *getShape(std::string shapeType)
    {
        if (shapeType == "Circle")
            return new Circle();
        else if (shapeType == "Square")
            return new Square();
        else if (shapeType == "Rectangle")
            return new Rectangle();

        return nullptr;
    }
};

int main()
{
    // 步骤 4 使用该工厂，通过传递类型信息来获取实体类的对象。

    ShapeFactory *shapeFactory = new ShapeFactory();

    Shape *shape1 = shapeFactory->getShape("Circle");
    shape1->draw();

    Shape *shape2 = shapeFactory->getShape("Square");
    shape2->draw();

    Shape *shape3 = shapeFactory->getShape("Rectangle");
    shape3->draw();

    return 0;
}
