#include<iostream>

#include<functional>

class ProgramA
{
public:
	void FunA1() { printf("I'am ProgramA.FunA1() and be called..\n"); }
	void FunA2() { printf("I'am ProgramA.FunA2() and be called..\n"); }
	
	static void FunA3() { printf("I'am ProgramA.FunA3() and be called..\n"); }
};

class ProgramB
{
	typedef std::function<void()> CallbackFun;
public:
	void FunB1(CallbackFun callback)
	{
		printf("I'am ProgramB.FunB2() and be called..\n");
		callback();
	}
};

void normFun() { printf("I'am normFun() and be called..\n"); }

int main()
{
	ProgramA PA;
	PA.FunA1();

	printf("\n");
	ProgramB PB;
	PB.FunB1(normFun);
	printf("\n");
	PB.FunB1(ProgramA::FunA3);
	printf("\n");
	PB.FunB1(std::bind(&ProgramA::FunA2, &PA));

	return 0;
}
