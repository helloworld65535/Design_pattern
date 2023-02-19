#include <iostream>

/*
 * ���ǽ�����һ�� Shape �ӿں�ʵ�� Shape �ӿڵ�ʵ���ࡣ��һ���Ƕ��幤���� ShapeFactory��
 * FactoryPatternDemo ��ʹ�� ShapeFactory ����ȡ Shape ����
 * ������ ShapeFactory ������Ϣ��CIRCLE / RECTANGLE / SQUARE�����Ա��ȡ�������������͡�
 */

// ���� 1 ����һ���ӿ�
class Shape
{
public:
    virtual void draw() = 0;
};

// ���� 2 ����ʵ�ֽӿڵ�ʵ����
class Circle : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "��һ��Բ" << std::endl;
    }
};

class Square : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "��һ��������" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    virtual void draw() override
    {
        std::cout << "��һ������" << std::endl;
    }
};

// ���� 3 ����һ�����������ɻ��ڸ�����Ϣ��ʵ����Ķ���
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
    // ���� 4 ʹ�øù�����ͨ������������Ϣ����ȡʵ����Ķ���

    ShapeFactory *shapeFactory = new ShapeFactory();

    Shape *shape1 = shapeFactory->getShape("Circle");
    shape1->draw();

    Shape *shape2 = shapeFactory->getShape("Square");
    shape2->draw();

    Shape *shape3 = shapeFactory->getShape("Rectangle");
    shape3->draw();

    return 0;
}
