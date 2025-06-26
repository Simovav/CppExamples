constexpr int cxpr_times_2(int a) { return a * 2; }//may be evaluated both at compile time or runtime
consteval int ceval_times_2(int a) { return a * 2; }//may only be evaluated at runtime

int main() {
	constexpr int a = 2;
	const int b = 3;
	int c = 4;
	
	constexpr int call_1 = cxpr_times_2(a);//compile time
	constexpr int call_2 = cxpr_times_2(2);//compile time
	constexpr int call_3 = cxpr_times_2(b);//compile time
	/*constexpr*/ int call_4 = cxpr_times_2(c); //Runtime

	ceval_times_2(3); //OK compile time
	ceval_times_2(a); //OK compile time
	ceval_times_2(b); //OK, b is constexpr
	//ceval_times_2(c); //ERROR: c is not constexpr, cannot evaluate at compile time
}