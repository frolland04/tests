#include <iostream>
#include <locale>
#include <iomanip>
#include <ctime>

int main()
{
    std::ostream & os{std::cout};

    std::locale def("");
    os.imbue(def);

    double nb{1234567.89};
    os << std::fixed << std::setprecision(2);
    os << nb << '\n';
        // 1 234 567,89

    std::locale fr("fr_FR.UTF-8");
    os.imbue(fr);
    os << "(FR) " << nb << '\n';
        // (FR) 1 234 567,89

    std::locale us("en_US.UTF-8");
    os.imbue(us);
    os << "(US) " << nb << '\n';
        // (US) 1,234,567.89

    std::time_t t = std::time(nullptr);
    std::tm * lt = std::localtime(&t);

    os.imbue(def);
    os << "" << std::put_time(lt, "%c") << '\n';
        // mar. 22 oct. 2024 11:44:43

    os.imbue(fr);
    os << "(FR) " << std::put_time(lt, "%c") << '\n';
        // (FR) mar. 22 oct. 2024 11:44:43

    os.imbue(us);
    os << "(US) " << std::put_time(lt, "%c") << '\n';
        // (US) Tue 22 Oct 2024 11:44:43 AM CEST

    double amount{115.0};
    os << std::showbase;

    os.imbue(def);
    os << "" << std::put_money(amount * 100) << '\n';
        // 115,00 €

    os.imbue(fr);
    os << "(FR) " << std::put_money(amount * 100) << '\n';
        // (FR) 115,00 €

    os.imbue(us);
    os << "(US) " << std::put_money(amount * 100) << '\n';
        // (US) $115.00

    // /usr/share/locale/fr/LC_MESSAGES/inkscape.mo Amount => Quantité

    using m = std::messages<char>;
    auto & f = std::use_facet<m>(fr);
    auto mo = f.open("inkscape", fr);
    os << "(FR) " << f.get(mo, 0, 0, "Amount") << std::endl;
        // (FR) Quantité

    return 0;
}
