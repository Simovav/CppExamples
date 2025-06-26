class Point2D {
private:
	int m_x{};
	int m_y{};

public:
	constexpr Point2D() noexcept = default;
	constexpr explicit Point2D(int value) noexcept : m_x(value), m_y(value) {}
	constexpr Point2D(int x, int y) noexcept : m_x(x), m_y(y) {}

	constexpr const int& getX() const noexcept { return m_x; }
	constexpr const int& getY() const noexcept { return m_y; }
	constexpr Point2D& setX(int x) noexcept { m_x = x; return *this; }
	constexpr Point2D& setY(int y) noexcept { m_y = y; return *this; }

	constexpr double length_sq() const noexcept { return m_x * m_x + m_y * m_y; }

	constexpr bool operator==(const Point2D& other) const noexcept {
		return m_x == other.m_x && m_y == other.m_y;
	}

	constexpr bool operator!=(const Point2D& other) const noexcept { return !(*this == other); }
};

#include <iostream>

static void printPoint(std::string_view ptname, const Point2D& pt) {
	//cpp23
	//std::println("the point {} is: ({},{})", ptname, pt.getX(), pt.getY());
	std::cout << "the point " << ptname <<
		" is : (" << pt.getX() << "," <<
		pt.getY() << ")" << std::endl;
}

constexpr Point2D BuildPoint() {
	Point2D P;
	P.setX(42);
	P.setY(35);
	return P;
}

int main()
{
	constexpr Point2D P(1, 2);
	constexpr Point2D Q(P.getX(), 3);

	constexpr double a = Point2D(2, 1).setX(4).getX();

	constexpr Point2D R = BuildPoint();

	const Point2D S(4, 5);
	printPoint("P", P);
	printPoint("Q", Q);
	printPoint("R", R);
	printPoint("S", S);

}
