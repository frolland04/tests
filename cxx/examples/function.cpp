int main() { 
        return EXIT_SUCCESS;
}

// By the way, main prototype is the same as the one in C.
int main(int argc, char **argv, char **envp) { 
	return EXIT_SUCCESS;
}




void function(int); 
void function(double);
void function(int, int);

int function(int); // Error, multiple declaration.

const int speed_light_mps{299'792'458};
const double pi{3.14};

function(speed_light_mps) // Call function(int).
function(pi)              // Call function(double).
function(pi, speed_light_mps) // Call function(int, int).

void function(double, double);

function(pi, speed_light_mps) // Error. Call to `function` is ambiguous.


int multiply_by_5(int v) { return v * 5 };
double multiply_by_5(double v) { return v * 5; };
long multiply_by_5(long v) { return v * 5; };

template<typename T> T multiply_by_5(T v) { return v * 5; };

// Bad
void function(int i, int j, int k);
void function(int i, int j) { function(i, j, 0); };
void function(int i) { function(i, 1); };
// Good
void function(int i, int j = 1, int k = 0);

function(3, 3, 3); // Calls f(3, 3, 3);
function(3, 3);    // Calls f(3, 3, 0);
function(3);       // Calls f(3, 1, 0);

void function(int i = 0, int j); // Error.

// Bad mixing example

void function(int i, int j = 0);
void function(int i);

function(0); // Error. Call to `function` is ambiguous.


