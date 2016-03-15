#include "calculator.h"
#include "ui_calculator.h"
#include <QMessageBox>
#include <cmath>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_about_triggered()
{
    QMessageBox::about(this, tr("About_Calculator.gui"),
                       tr("<h2>Calculator 1.0</h2>"
                          "<p> Copyright &copy; John Roof. CSCI60. Winter 2015. "
                          "Santa Clara University. "
                          "A simple calculator. Enjoy!"));
}

void Calculator::on_quit_triggered()
{
    exit(0);
}

void Calculator::update_calculator()
{
    ui->left_operand->setValue(left);
    ui->right_operand->setValue(right);
    ui->memory->setValue(memory);
}

void Calculator::set_left(int & x)
{
    left = x;
}

void Calculator::set_right(int & x)
{
    right = x;
}

void Calculator::set_memory(int & x)
{
    memory = x;
}

void Calculator::on_left_operand_valueChanged(int arg1)
{
    set_left(arg1);
    update_calculator();
}

void Calculator::on_right_operand_valueChanged(int arg1)
{
    set_right(arg1);
    update_calculator();
}

void Calculator::on_add_clicked()
{
    int i;
    i = right + left;
    set_left(i);
    update_calculator();
}

void Calculator::on_subtract_clicked()
{
    int i;
    i = left - right;
    set_left(i);
    update_calculator();
}

void Calculator::on_multiply_clicked()
{
    int i;
    i = left*right;
    set_left(i);
    update_calculator();
}

void Calculator::on_divide_clicked()
{
    if(right == 0)
    {
    QMessageBox msgBox;
     msgBox.setText("Can't divide by zero!!");
     msgBox.exec();
    }
    else
    {
    int i;
    i = (left/right);
    set_left(i);
    update_calculator();
    }
}

void Calculator::on_remainder_clicked()
{
    if(right == 0)
    {
    QMessageBox msgBox;
     msgBox.setText("Can't divide by zero!!");
     msgBox.exec();
    }
    else
    {
    int i;
    i = (left%right);
    set_left(i);
    update_calculator();
    }
}


void Calculator::on_power_clicked()
{
    int i;
    i = pow(left, right);
    set_left(i);
    update_calculator();
}

void Calculator::on_factorial_clicked()
{
    int x = 1;
    for(int i = 1; i <= left; i++)
    {
        x = x*i;
    }
    set_left(x);
    update_calculator();
}

void Calculator::on_memory_valueChanged(int arg1)
{
    memory = arg1;
    update_calculator();
}

void Calculator::on_memory_save_clicked()
{
    int i;
    i = left;
    set_memory(i);
    update_calculator();
}

void Calculator::on_memory_recall_clicked()
{
    set_right(memory);
    update_calculator();
}
