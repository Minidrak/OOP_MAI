#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

template <class T>
struct Point {
    T x;
    T y;
};

template <class T>
class Figure {
public:
    virtual ~Figure() noexcept = default;
    virtual double Area() const noexcept = 0;
    virtual Point<T> Center() const noexcept = 0;
    virtual void PrintInfo() const = 0;
};

template <class T>
class Rectangle : public Figure<T> {
private:
    Point<T> _first;
    Point<T> _second;
    Point<T> _third;
    Point<T> _fourth;

public:
    Rectangle(Point<T> const &first, Point<T> const &second, Point<T> const &third, Point<T> const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth) {}

    double Area() const noexcept override {
        double side1 = std::sqrt((_first.x - _second.x) * (_first.x - _second.x) + (_first.y - _second.y) * (_first.y - _second.y));
        double side2 = std::sqrt((_second.x - _third.x) * (_second.x - _third.x) + (_second.y - _third.y) * (_second.y - _third.y));
        return side1 * side2;
    }

    Point<T> Center() const noexcept override {
        Point<T> center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    void PrintInfo() const override {
        std::cout << "Rectangle Vertices: (" << _first.x << ", " << _first.y << "), "
                  << "(" << _second.x << ", " << _second.y << "), "
                  << "(" << _third.x << ", " << _third.y << "), "
                  << "(" << _fourth.x << ", " << _fourth.y << ")" << std::endl;
    }
};

template <class T>
class Trapezoid : public Figure<T> {
private:
    Point<T> _first;
    Point<T> _second;
    Point<T> _third;
    Point<T> _fourth;

public:
    Trapezoid(Point<T> const &first, Point<T> const &second, Point<T> const &third, Point<T> const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth) {}

    double Area() const noexcept override {
        double base1 = std::sqrt((_first.x - _second.x) * (_first.x - _second.x) + (_first.y - _second.y) * (_first.y - _second.y));
        double base2 = std::sqrt((_second.x - _third.x) * (_second.x - _third.x) + (_second.y - _third.y) * (_second.y - _third.y));
        double height = std::abs(_first.y - _third.y);
        return ((base1 + base2) / 2) * height;
    }

    Point<T> Center() const noexcept override {
        Point<T> center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    void PrintInfo() const override {
        std::cout << "Trapezoid Vertices: (" << _first.x << ", " << _first.y << "), "
                  << "(" << _second.x << ", " << _second.y << "), "
                  << "(" << _third.x << ", " << _third.y << "), "
                  << "(" << _fourth.x << ", " << _fourth.y << ")" << std::endl;
    }
};

template <class T>
class Rhombus : public Figure<T> {
private:
    Point<T> _first;
    Point<T> _second;
    Point<T> _third;
    Point<T> _fourth;

public:
    Rhombus(Point<T> const &first, Point<T> const &second, Point<T> const &third, Point<T> const &fourth)
        : _first(first), _second(second), _third(third), _fourth(fourth) {}

    double Area() const noexcept override {
        double sideAB = std::sqrt((_second.x - _first.x) * (_second.x - _first.x) + (_second.y - _first.y) * (_second.y - _first.y));
        double sideBC = std::sqrt((_third.x - _second.x) * (_third.x - _second.x) + (_third.y - _second.y) * (_third.y - _second.y));
        return sideAB * sideBC * 0.5;
    }

    Point<T> Center() const noexcept override {
        Point<T> center;
        center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
        center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
        return center;
    }

    void PrintInfo() const override {
        std::cout << "Rhombus Vertices: (" << _first.x << ", " << _first.y << "), "
                  << "(" << _second.x << ", " << _second.y << "), "
                  << "(" << _third.x << ", " << _third.y << "), "
                  << "(" << _fourth.x << ", " << _fourth.y << ")" << std::endl;
    }
};

template <class T>
class FigureArray {
private:
    std::vector<std::shared_ptr<Figure<T>>> figures;

public:
    void AddFigure(std::shared_ptr<Figure<T>> figure) {
        figures.push_back(figure);
    }

    void PrintAllFiguresInfo() const {
        for (const auto &figure : figures) {
            figure->PrintInfo();
            std::cout << "Center: (" << figure->Center().x << ", " << figure->Center().y << ")" << std::endl;
            std::cout << "Area: " << figure->Area() << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

    double TotalArea() const {
        double totalArea = 0;
        for (const auto &figure : figures) {
            totalArea += figure->Area();
        }
        return totalArea;
    }

    void RemoveFigure(size_t index) {
        if (index < figures.size()) {
            figures.erase(figures.begin() + index);
        }
    }
};

int main() {
    FigureArray<double> figureArray;

    Point<double> first{0.0, 0.0};
    Point<double> second{1.0, 0.0};
    Point<double> third{1.0, 1.0};
    Point<double> fourth{0.0, 1.0};
    auto rectangle = std::make_shared<Rectangle<double>>(first, second, third, fourth);
    figureArray.AddFigure(rectangle);

    Point<double> trapezoidFirst{0.0, 0.0};
    Point<double> trapezoidSecond{1.0, 0.0};
    Point<double> trapezoidThird{2.0, 1.0};
    Point<double> trapezoidFourth{-1.0, 1.0};
    auto trapezoid = std::make_shared<Trapezoid<double>>(trapezoidFirst, trapezoidSecond, trapezoidThird, trapezoidFourth);
    figureArray.AddFigure(trapezoid);

    Point<double> rhombusFirst{0.0, 0.0};
    Point<double> rhombusSecond{1.0, 1.0};
    Point<double> rhombusThird{0.0, 2.0};
    Point<double> rhombusFourth{-1.0, 1.0};
    auto rhombus = std::make_shared<Rhombus<double>>(rhombusFirst, rhombusSecond, rhombusThird, rhombusFourth);
    figureArray.AddFigure(rhombus);

    std::cout << "Information about all figures:" << std::endl;
    figureArray.PrintAllFiguresInfo();

    std::cout << "Total area of all figures: " << figureArray.TotalArea() << std::endl;

    size_t indexToRemove = 1;
    figureArray.RemoveFigure(indexToRemove);

    std::cout << "Information about remaining figures after removing one:" << std::endl;
    figureArray.PrintAllFiguresInfo();

    return 0;
}

