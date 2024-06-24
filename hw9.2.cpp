#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction()
	{
		numerator_ = 1;
		denominator_ = 1;
	}

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	int get_numerator()
	{
		return numerator_;
	}

	int get_denominator()
	{
		return denominator_;
	}
	
	// Переопределение  Сложения
	Fraction operator+(Fraction right)
	{
		int temp_numerator = numerator_ * right.denominator_ + right.numerator_ * denominator_;
		int temp_denominator = denominator_ * right.denominator_;
		if ((temp_numerator % denominator_ == 0) && temp_denominator % denominator_ == 0)
		{
			temp_numerator = temp_numerator / denominator_;
			temp_denominator = temp_denominator / denominator_;
		}
		if ((temp_numerator % right.denominator_ == 0) && temp_denominator % right.denominator_ == 0)
		{
			temp_numerator = temp_numerator / right.denominator_;
			temp_denominator = temp_denominator / right.denominator_;
		}
		return Fraction(temp_numerator, temp_denominator);
	}

	//Переопределение  Вычитание
	Fraction operator-(Fraction right)
	{
		int temp_numerator = numerator_* right.denominator_ - right.numerator_ * denominator_;
		int temp_denominator = denominator_ * right.denominator_;
		if ((temp_numerator % denominator_ == 0) && temp_denominator % denominator_ == 0)
		{
			temp_numerator = temp_numerator / denominator_;
			temp_denominator = temp_denominator / denominator_;
		}
		if ((temp_numerator % right.denominator_ == 0) && temp_denominator % right.denominator_ == 0)
		{
			temp_numerator = temp_numerator / right.denominator_;
			temp_denominator = temp_denominator / right.denominator_;
		}
		return Fraction(temp_numerator, temp_denominator);
	}

	//Переопределение  Унарный минус
	Fraction& operator-()
	{
		numerator_ = - numerator_;
		denominator_ = denominator_;
		return *this;
	}

	// Переопределение  Умножение
	Fraction operator*(Fraction right)
	{
		int temp_numerator = numerator_* right.numerator_;
		int temp_denominator = denominator_ * right.denominator_;
		if ((temp_numerator % denominator_ == 0) && temp_denominator % denominator_ == 0)
		{
			temp_numerator = temp_numerator / denominator_;
			temp_denominator = temp_denominator / denominator_;
		}
		if ((temp_numerator % right.denominator_ == 0) && temp_denominator % right.denominator_ == 0)
		{
			temp_numerator = temp_numerator / right.denominator_;
			temp_denominator = temp_denominator / right.denominator_;
		}
		return Fraction(temp_numerator, temp_denominator);
	}

	// Переопределение  Деление
	Fraction operator/(Fraction right)
	{
		int temp_numerator = numerator_ * right.denominator_;
		int temp_denominator = denominator_ * right.numerator_;
		if ((temp_numerator % denominator_ == 0) && temp_denominator % denominator_ == 0)
		{
			temp_numerator = temp_numerator / denominator_;
			temp_denominator = temp_denominator / denominator_;
		}
		if ((temp_numerator % right.denominator_ == 0) && temp_denominator % right.denominator_ == 0)
		{
			temp_numerator = temp_numerator / right.denominator_;
			temp_denominator = temp_denominator / right.denominator_;
		}
		return Fraction(temp_numerator, temp_denominator);
	}

	// Переопределение постфиксный и префиксный инкремент и декремент
	Fraction& operator++()
	{
		numerator_ = numerator_ + denominator_;
		return *this;
	}
	Fraction& operator++(int)
	{
		numerator_ = numerator_ + denominator_;
		return *this;
	}
	Fraction& operator--()
	{
		numerator_ = numerator_ - denominator_;
		return *this;
	}
	Fraction& operator--(int)
	{
		numerator_ = numerator_ - denominator_;
		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian"); // задать русский текст
	std::system("chcp 1251"); // настроить кодировку консоли
	std::system("cls"); // очистить экран

	int f1n, f1d, f2n, f2d;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> f1n;
	std::cout << std::endl << "Введите знаменатель  дроби 1: ";
	std::cin >> f1d;
	std::cout << std::endl << "Введите числитель дроби 2: ";
	std::cin >> f2n;
	std::cout << std::endl << "Введите знаменатель  дроби 2: ";
	std::cin >> f2d;

	Fraction f1(f1n, f1d), f2(f2n, f2d), f3(1,1);

	std::cout << std::endl << "сложение" << std::endl;
	f3 = f1 + f2;
	std::cout << f1.get_numerator() << "/" << f1.get_denominator() << " + " << f2.get_numerator() << "/" << f2.get_denominator() << " = " << f3.get_numerator() << "/" << f3.get_denominator()<<std::endl;
	
	std::cout << std::endl << "вычитание" << std::endl;
	f3 = f1 - f2;
	std::cout << f1.get_numerator() << "/" << f1.get_denominator() << " - " << f2.get_numerator() << "/" << f2.get_denominator() << " = " << f3.get_numerator() << "/" << f3.get_denominator() << std::endl;
	
	std::cout << std::endl << "умножение" << std::endl;
	f3 = f1 * f2;
	std::cout << f1.get_numerator() << "/" << f1.get_denominator() << " * " << f2.get_numerator() << "/" << f2.get_denominator() << " = " << f3.get_numerator() << "/" << f3.get_denominator() << std::endl;
	
	std::cout << std::endl << "деление" << std::endl;
	f3 = f1 / f2;
	std::cout << f1.get_numerator() << "/" << f1.get_denominator() << " / " << f2.get_numerator() << "/" << f2.get_denominator() << " = " << f3.get_numerator() << "/" << f3.get_denominator() << std::endl;
	
	std::cout << std::endl << "операция с префисным инкрементом" << std::endl;
	std::cout <<"++" << f1.get_numerator() << "/" << f1.get_denominator() << " * " << f2.get_numerator() << "/" << f2.get_denominator() << " = " << f3.get_numerator() << "/" << f3.get_denominator() << std::endl;
	f3 = ++f1 * f2;
	std::cout <<"Значение дроби 1 = " << f1.get_numerator() << "/" << f1.get_denominator() << std::endl;
	
	std::cout << std::endl << "операция с постфиксным декрементом" << std::endl;
	std::cout << f1.get_numerator()  << "/" << f1.get_denominator() << "-- * " << f2.get_numerator() << "/" << f2.get_denominator() << " = " << f3.get_numerator() << "/" << f3.get_denominator() << std::endl;
	f3 = f1-- * f2;
	std::cout << "Значение дроби 1 = " << f1.get_numerator() << "/" << f1.get_denominator() << std::endl;
	
	std::cout << std::endl << "унарный минус" << std::endl;
	f3 = -f1;
	std::cout << "Значение дроби 1 = " << f3.get_numerator() << "/" << f3.get_denominator() << std::endl;

	return 92;
}