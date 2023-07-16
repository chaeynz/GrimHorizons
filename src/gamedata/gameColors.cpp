#include "gameColors.hpp"

std::ostream& red(std::ostream& os) {
	return os << "\033[31m";
}
std::ostream& green(std::ostream& os) {
	return os << "\033[32m";
}
std::ostream& blue(std::ostream& os) {
	return os << "\033[34m";
}
std::ostream& orange(std::ostream& os) {
	return os << "\033[38;5;214m";
}
std::ostream& purple(std::ostream& os) {
	return os << "\033[38;5;135m";
}
std::ostream& reset(std::ostream& os) {
	return os << "\033[0m";
}

//std::ostream& purple(std::ostream& os) {
//	return os << "\033[35m";
//