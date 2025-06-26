class Point2D {
private:
	int m_x;
	int m_y;

public:
	Point2D() :m_x(0), m_y(0) {}
	Point2D(int x, int y) : m_x(x), m_y(y) {}
	Point2D(int val) : m_x(val), m_y(val) {}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }

	bool operator==(const Point2D& other) const {
		return m_x == other.m_x && m_y == other.m_y;
	}

	bool operator!=(const Point2D& other) const { return !(*this == other); }
};

#include <iostream>

int main()
{
	Point2D point(2, 3);
	point.setX(5);
	std::cout << "The point is: (" << point.getX() << "," << point.getY() << ")" << std::endl;

	//cpp23
	// std::println("The point is: ({},{})", point.getX(), point.getY());
}
