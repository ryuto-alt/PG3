#include <stdio.h>

// 親クラス
class Shape
{
public:
    virtual void Size() = 0;
    virtual void Draw() = 0;

protected:
    float size;
};

// 円クラス
class Circle : public Shape
{
public:
    void Size() override;
    void Draw() override { printf("円の面積: %f\n", size); }
};

// 四角クラス
class Rectangle : public Shape
{
public:
    void Size() override;
    void Draw() override { printf("矩形の面積: %f\n", size); }

private:
    float width, height;
};

void Circle::Size()
{
    float radius = 5.0f;
    printf("円の半径: %f\n", radius);
    size = radius * radius * 3.14f; // πr^2
}

void Rectangle::Size()
{
    width = 5.0f;
    height = 10.0f;
    printf("矩形の幅: %f, 高さ: %f\n", width, height);
    size = width * height; // 幅×高さ
}

int main(void)
{
    Shape* shapes[2] = { new Circle(), new Rectangle() };

    shapes[0]->Size();
    shapes[1]->Size();

    shapes[0]->Draw();
    shapes[1]->Draw();

    delete shapes[0];
    delete shapes[1];

    return 0;
}
