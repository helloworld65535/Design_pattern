#include <iostream>
/* 
我们将创建 Shape 和 Color 接口和实现这些接口的实体类。
下一步是创建抽象工厂类 AbstractFactory。
接着定义工厂类 ShapeFactory 和 ColorFactory，这两个工厂类都是扩展了 AbstractFactory。
然后创建一个工厂创造器/生成器类 FactoryProducer。
AbstractFactoryPatternDemo 类使用 FactoryProducer 来获取 AbstractFactory 对象。
它将向 AbstractFactory 传递形状信息 Shape（CIRCLE / RECTANGLE / SQUARE），以便获取它所需对象的类型。
同时它还向 AbstractFactory 传递颜色信息 Color（RED / GREEN / BLUE），以便获取它所需对象的类型。 */

/* 步骤 1
为形状创建一个接口。
*/
class Shape
{
public:
    virtual void draw() = 0;
};

/* 步骤 2
创建实现接口的实体类。
*/
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

/* 步骤 3
为颜色创建一个接口。
*/
class Color
{
public:
    virtual void fill() = 0;
};

/* 步骤4
创建实现接口的实体类。
*/
class Red : public Color
{
public:
    virtual void fill() override
    {
        std::cout << "使用红色填充" << std::endl;
    }
};
class Green : public Color
{
public:
    virtual void fill() override
    {
        std::cout << "使用绿色填充" << std::endl;
    }
};
class Blue : public Color
{
public:
    virtual void fill() override
    {
        std::cout << "使用蓝色填充" << std::endl;
    }
};

/* 步骤 5
为 Color 和 Shape 对象创建抽象类来获取工厂。
*/

class AbstractFactory
{
public:
    virtual Color *getColor(std::string color) = 0;
    virtual Shape *getShape(std::string shape) = 0;
};

/* 步骤 6
创建扩展了 AbstractFactory 的工厂类，
基于给定的信息生成实体类的对象。
*/

class ShapeFactory : public AbstractFactory
{
public:
    virtual Color *getColor(std::string color) override
    {
        return nullptr;
    }

    virtual Shape *getShape(std::string shape) override
    {
        if (shape == "Circle")
            return new Circle();
        else if (shape == "Square")
            return new Square();
        else if (shape == "Rectangle")
            return new Rectangle();

        return nullptr;
    }
};
class ColorFactory : public AbstractFactory
{
public:
    virtual Color *getColor(std::string color) override
    {
        if (color == "Red")
            return new Red();
        else if (color == "Green")
            return new Green();
        else if (color == "Blue")
            return new Blue();

        return nullptr;
    }

    virtual Shape *getShape(std::string shapeType) override
    {
        return nullptr;
    }
};

/* 步骤 7
创建一个工厂创造器/生成器类，
通过传递形状或颜色信息来获取工厂。
*/
class FactoryProducer
{
public:
    AbstractFactory *getFactory(std::string choice)
    {
        if (choice == "Shape")
            return new ShapeFactory();
        else if (choice == "Color")
            return new ColorFactory();

        return nullptr;
    }
};

/* 步骤 8
使用 FactoryProducer 来获取 AbstractFactory，
通过传递类型信息来获取实体类的对象。
*/
int main()
{
    AbstractFactory *shapeFactory = FactoryProducer().getFactory("Shape");
    Shape *shape1 = shapeFactory->getShape("Circle");
    shape1->draw();

    Shape *shape2 = shapeFactory->getShape("Square");
    shape2->draw();

    Shape *shape3 = shapeFactory->getShape("Rectangle");
    shape3->draw();

    AbstractFactory *colorFactory = FactoryProducer().getFactory("Color");
    Color *color1 = colorFactory->getColor("Red");
    color1->fill();

    Color *color2 = colorFactory->getColor("Green");
    color2->fill();

    Color *color3 = colorFactory->getColor("Blue");
    color3->fill();

    return 0;
}