class IntWrapper {
private:
	int m_val{};
public:
	constexpr explicit IntWrapper(int val) noexcept :m_val(val) {}

	constexpr const int& read() const noexcept {
		return m_val; 
	}
	constexpr int squared() const noexcept {
		return m_val * m_val;
	}

	void write(int val) noexcept { m_val = val; }
};

int main() {
	IntWrapper wr_1(100);
	constexpr IntWrapper wr_2(-1);

	int a = wr_1.read();//runtime
	int b = wr_2.read();//runtime

	//constexpr int c = wr_1.read(); //ERROR
	constexpr int d = wr_2.read(); //OK wr_2 is constexpr
	constexpr int e = wr_2.squared();//OK
}