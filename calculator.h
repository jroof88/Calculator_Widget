#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void on_about_triggered();

    void on_quit_triggered();

    void update_calculator();

    void set_left(int & x);

    void set_right(int & x);

    void set_memory(int & x);

    void on_left_operand_valueChanged(int arg1);

    void on_right_operand_valueChanged(int arg1);

    void on_add_clicked();

    void on_subtract_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_remainder_clicked();

    void on_power_clicked();

    void on_factorial_clicked();

    void on_memory_valueChanged(int arg1);

    void on_memory_save_clicked();

    void on_memory_recall_clicked();

private:
    Ui::Calculator *ui;
    int left, right, memory;
    // ^^Three integer variables representing the left operand, right operand, and memory storing
};

#endif // CALCULATOR_H
