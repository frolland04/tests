int i{0};

int& j{i};          // `i` and `j` are the same variable.

const int &g{1};    // But it is bad.
const int g{1};     // Rule: Use the simple tools.

const int i{0};
int &j = i;         // Error. Less constrain.

int i{0};
const int & j = i;  // OK, more constrain.

i = 1;              // OK.
j = 2;              // Error. Through `j`, the data is const.

void read_only(const std::string &str) {
	// Have a read only access to the given argument.
};

void read_write(std::string &str) {
	// Have read-write access to the given argument.
};

std::string data{"my data"};

read_only(data); // `read_only()` have a read only access to `data`.
read_write(data; // `read_write()` have a read write access to `data`.

read_only("some data"); // Constant can be const references.


namespace {
std::string hidden_variable{"secret string"};
}

const std::string &read_variable() {
	return hidden_variable;
}

std::string &write_variable() {
	return hidden_variable;
}

bool b{read_variable() == "secret string"}; // b is `true`.
write_variable() = "new secret";
b = read_variable() == "secret string"};    // b is `false`.
read_variable() = "secret";                 // Error: `read_variable() gives const access.
