#include "../../header-files/Number/Number.h"

#include <sstream>
#include <string>
#include <utility>
#include <cassert>

#include "header-files/Number/Octal.h"

Number::Number(std::string number) : num(std::move(number)) {}

Number::Number(const Octal &o) : num(o.num) {}

Number::Number(const Hexadecimal &h) : num(h.num) {}

Number::Number(const Binary &b) : num(b.num) {}

Number::Number(const Decimal &d) : num(d.num) {}

std::string Number::to_string_with_precision(const long double value, int precision) {
	std::ostringstream out;
	out.precision(precision);
	out << std::fixed << value;
	return out.str();
}

void Number::clean_number(std::string &num) {
	if (num == "0" || num == "0.0" || num.empty()) {
		num = "0.0";
		return;
	}

	if (num.find('.') == -1)
		num += ".0";

	bool isItNegative = num.at(0) == '-';
	num = isItNegative ? num.substr(1, num.length()) : num;

	while (num.at(0) == '0' && num.at(1) != '.')
		num = num.substr(1, num.length());

	while (num.at(num.length() - 1) == '0' && num.at(num.length() - 2) != '.')
		num = num.substr(0, num.length() - 1);

	num = (num == "-." || num == ".") ? "0.0" : num;

	num = isItNegative ? "-" + num : num;
}

std::string Number::sum(std::string val1, std::string val2) {
	bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
	// remove the first character if it is negative
	val1[0] == '-' ? val1.erase(0, 1) : "";
	val2[0] == '-' ? val2.erase(0, 1) : "";
	std::string result;

	if (!val1IsNegative && val2IsNegative) { // 13 + -52 = 13 - 52
		return this->sub(val1, val2);
	} else if (val1IsNegative && !val2IsNegative) { // -13 + 52 = 52 - 13;
		return this->sub(val2, val1);
	} else if (val1IsNegative && val2IsNegative) { // -13 + -52 = "-" + (13 + 52)
		return "-" + this->sum(val1, val2);
	}

// integer to .
  start:
	if (val1.find('.') != -1 && val2.find('.') != -1) {
		if (val1.find('.') > val2.find('.'))
			while (val1.find('.') != val2.find('.'))
				val2.insert(0, "0");
		else if (val1.find('.') < val2.find('.'))
			while (val1.find('.') != val2.find('.'))
				val1.insert(0, "0");
	} else if (val2.find('.') == -1) {
		val2.append(".0");
		goto start;
	} else if (val1.find('.') == -1) {
		val1.append(".0");
		goto start;
	}

	// . to end
	if (val1.substr(val1.find('.') + 1, val1.length()).length() < val2.substr(val2.find('.') + 1, val2.length()).length())
		while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
			val1.append("0");
	else if (val1.substr(val1.find('.') + 1, val1.length()).length() > val2.substr(val2.find('.') + 1, val2.length()).length())
		while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
			val2.append("0");

	int got = 0, index = val1.length() - 1, i = 0;
	while (index != -1) {
		if (val1[index] == '.') {
			result.insert(0, ".");
			index--;
			continue;
		}

		i = int(val1[index] - '0') + int(val2[index] - '0') + got;

		got = 0;
		if (i >= 10) {
			got += 1;
			i %= 10;
		}
		result.insert(result.begin(), char(i + '0'));
		index--;
	}

	clean_number(result);

	return result;
}

std::string Number::sub(std::string val1, std::string val2) {
	bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
	// remove the first character if it is negative
	val1[0] == '-' ? val1.erase(0, 1) : "";
	val2[0] == '-' ? val2.erase(0, 1) : "";
	std::string result;
	clean_number(val1);
	clean_number(val2);
	if (val1.empty() || val1 == "0.0")
		return "-" + val2;
	if (!val1IsNegative && val2IsNegative) { // - - = +
		return this->sum(val1, val2);
	} else if (val1IsNegative && !val2IsNegative) {
		return "-" + this->sum(val2, val1);
	} else if (val1IsNegative && val2IsNegative) {
		return this->sub(val2, val1);
	} else if (std::stod(val1) < std::stod(val2)) {
		return "-" + this->sub(val2, val1);
	}

	// integer to .
	if (val1.find('.') != -1 && val2.find('.') != -1) {
		if (val1.find('.') > val2.find('.'))
			while (val1.find('.') != val2.find('.'))
				val2.insert(val2.begin(), '0');
		else if (val1.find('.') < val2.find('.'))
			while (val1.find('.') != val2.find('.'))
				val1.insert(val1.begin(), '0');
	} else if (val2.find('.') == -1)
		val2.append(".0");
	else if (val1.find('.') == -1)
		val1.append(".0");

	// . to end
	if (val1.substr(val1.find('.') + 1, val1.length()).length() < val2.substr(val2.find('.') + 1, val2.length()).length())
		while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
			val1.append("0");
	else if (val1.substr(val1.find('.') + 1, val1.length()).length() > val2.substr(val2.find('.') + 1, val2.length()).length())
		while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
			val2.append("0");

	int borrow = 0, index = val1.length() - 1, i = 0;
	while (index != -1) {
		if (val1[index] == '.') {
			result.insert(result.begin(), '.');
			index--;
			continue;
		}

		i = int(val1[index] - '0') - int(val2[index] - '0') - borrow;

		borrow = 0;
		if (i < 0) {
			borrow += 1;
			i += 10;
		}
		result.insert(result.begin(), char(i + '0'));
		index--;
	}

	clean_number(result);

	return result;
}

std::string Number::mul(std::string val1, std::string val2) {
	// setting locale for qapplication changes(. might be , in region)
	const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
	std::setlocale(LC_NUMERIC, "C");
	clean_number(val1);
	clean_number(val2);

	bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
	// remove the first character if it is negative
	val1[0] == '-' ? val1.erase(0, 1) : "";
	val2[0] == '-' ? val2.erase(0, 1) : "";

	if (!val1IsNegative && val2IsNegative) { // + * - = -
		return "-" + this->mul(val1, val2);
	} else if (val1IsNegative && !val2IsNegative) { // - * + = -
		return "-" + this->mul(val1, val2);
	} else if (val1IsNegative && val2IsNegative) { // - * - = +
		return this->mul(val1, val2);
	}

	int decLoc = val1.substr(val1.find('.') + 1, val1.length()).length() + val2.substr(val2.find('.') + 1, val2.length()).length();
	std::string tVal1 = val1.substr(0, val1.find('.')) + val1.substr(val1.find('.') + 1, val1.length());
	std::string tVal2 = val2.substr(0, val2.find('.')) + val2.substr(val2.find('.') + 1, val2.length());

	auto *results = new std::string[tVal2.length()];
	int firstLen;
	for (int i = tVal2.length() - 1; i >= 0; i--) {
		std::string n;
		int got = 0;
		for (int j = tVal1.length() - 1; j >= 0; j--) {
			int res = int(tVal2[i] - '0') * int(tVal1[j] - '0') + got;
			got = static_cast<int>(res / 10);
			n.insert(n.begin(), static_cast<char>(res % 10 + '0'));
		}
		if (got > 0)
			n.insert(n.begin(), static_cast<char>(got + '0'));

		if (i == tVal2.length() - 1)
			firstLen = n.length();

		results[i] = std::string(i - (n.length() - firstLen), '0') + n + std::string(tVal2.length() - i - 1, '0');
	}
	std::string result = "0";
	for (int i = 0; i < tVal2.length(); i++) {
		result = this->sum(result, results[i]);
	}

	result.erase(result.size() - 2); // remove last 2 items(.0)
	result.insert(result.length() - decLoc, ".");

	// setting the locale to old
	std::setlocale(LC_NUMERIC, oldLocale.c_str());
	clean_number(result);

	return result;
}

std::string Number::div(std::string val1, std::string val2) {
	bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
	// remove the first character if it is negative
	val1[0] == '-' ? val1.erase(0, 1) : "";
	val2[0] == '-' ? val2.erase(0, 1) : "";

	if (!val1IsNegative && val2IsNegative) { // + / - = -
		return "-" + this->div(val1, val2);
	} else if (val1IsNegative && !val2IsNegative) { // - / + = -
		return "-" + this->div(val1, val2);
	} else if (val1IsNegative && val2IsNegative) { // - / - = +
		return this->div(val1, val2);
	}

	std::string result = "";
	// create decimal point if not exist
	if (val1.find('.') == std::string::npos) {
		val1 += ".";
	}
	if (val2.find('.') == std::string::npos) {
		val2 += ".";
	}

	// make decimal points equal
	int i = val1.substr(val1.find('.') + 1, val1.length()).length(), j = val2.substr(val2.find('.') + 1, val2.length()).length();
	if (i > j) {
		val2.append(std::string(i - j, '0'));
	} else if (j > i) {
		val1.append(std::string(j - i, '0'));
	}

	// erase decimal points
	val1.erase(val1.find('.'), 1);
	val2.erase(val2.find('.'), 1);

	// divide and get remainder
	unsigned long long divisor = stoull(val2);
	unsigned long long remainder = stoull(val1) % divisor;
	result += std::to_string(static_cast<unsigned long long>(stoull(val1) / divisor));
	if (remainder != 0) {
		result += ".";
		std::string temp;
		while (remainder != 0) {
			remainder *= 10;
			if (remainder < divisor) {
				result += "0";
			} else if (remainder > divisor) {
				result += std::to_string(remainder / divisor);
				remainder %= divisor;
			} else {
				result += std::to_string(remainder / divisor);
				break;
			}
			// break the loop if the result is repeating
			if (result.substr(result.find('.') + 1, result.length()).length() > 16) {
				temp = result.substr(result.length() - 16, result.length());
				if (result.find(temp, result.find(temp) + 1) != std::string::npos) {
					result = result.substr(0, result.length() - 16);
					break;
				}
			}
		}
	}

	return result;
}
