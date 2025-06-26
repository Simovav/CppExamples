class Point2D {
private:
	int m_x{};
	int m_y{};

public:
	constexpr Point2D() = default;
	constexpr explicit Point2D(int value) : m_x(value), m_y(value) {}
	constexpr Point2D(int x, int y) : m_x(x), m_y(y) {}

	constexpr const int& getX() const noexcept { return m_x; }
	constexpr const int& getY() const noexcept { return m_y; }
	void setX(int x) noexcept { m_x = x; }
	void setY(int y) noexcept { m_y = y; }

	constexpr double length_sq() const noexcept { return m_x * m_x + m_y * m_y; }

	constexpr bool operator==(const Point2D& other) const noexcept {
		return m_x == other.m_x && m_y == other.m_y;
	}

	constexpr bool operator!=(const Point2D& other) const noexcept { return !(*this == other); }
};

#include <iostream>

int main() {
	Point2D P(2, 1);
	P.setX(4);

	std::cout << "P: (" << P.getX() << "," << P.getY() << ")\n";

    //cpp23
	//std::println("P: ({},{})", P.getX(), P.getY());

	Point2D const Q(2, 3);
	//Q.setX(3); // ERROR - Q is constant, cannot call a non const method
	
	std::cout << "Q: (" << Q.getX() << "," << Q.getY() << ")\n";
	//std::println("Q: ({},{})", Q.getX(), Q.getY()); //Ok, those are const methods.
}