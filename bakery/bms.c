#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int choice;
int customer_id;
char username[50];
char password[50];
char id_input[10];
#define MAX_LINE 100
int current_date;
int current_month;
int current_year;
int current_hr;
int current_min;
int current_sec;

typedef struct
{
    char name[30];
    int quantity;
    float price;
} Item;

typedef struct
{
    char name[30];
    int quantity;
    float price;
} Buy_Item;

void time_date()
{
    time_t current_time;
    time(&current_time);
    struct tm *local_time = localtime(&current_time);

    current_date = local_time->tm_mday;
    current_month = local_time->tm_mon + 1;
    current_year = local_time->tm_year + 1900;
    current_hr = local_time->tm_hour;
    current_min = local_time->tm_min;
    current_sec = local_time->tm_sec;
}
int menu_file()
{
    FILE *file = fopen("bakery/menu.csv", "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        file = fopen("bakery/menu.csv", "w");
        if (file)
            fclose(file);
        return 0;
    }
}
int id_no_file()
{
    FILE *file = fopen("bakery/id_alloted.csv", "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        file = fopen("bakery/id_alloted.csv", "w");
        fprintf(file,"849");   // starting id if you want tpo start from any other no. default is 849
        if (file)
            fclose(file);
        return 0;
    }
}
int id_generator()
{
    id_no_file();
    FILE *id_file = fopen("bakery/id_alloted.csv", "r");
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), id_file))
    {
        customer_id = atoi(line);
        customer_id = customer_id + 1;
    }
    fclose(id_file);
}
int customer_file()
{
    FILE *file = fopen("bakery/customer.csv", "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        file = fopen("bakery/customer.csv", "w");
        if (file)
            fclose(file);
        return 0;
    }
}
int check_admin(const char *username, const char *password)
{
    FILE *file = fopen("bakery/admin.csv", "r");
    if (!file)
    {
        file = fopen("bakery/admin.csv", "w");
        return 0;
    }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file))
    {
        char *file_username = strtok(line, ",");
        char *file_password = strtok(NULL, ",");

        if (file_password)
        {
            file_password[strcspn(file_password, "\n")] = 0;
        }

        if (file_password && file_username)
        {
            if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
            {
                fclose(file);

                return 1;
            }
        }
    }
    fclose(file);
    return 0;
}
int add_items()
{
    int items_count = 0;

    printf("How many items you want to add :");
    scanf("%d", &items_count);

    FILE *file = fopen("bakery/menu.csv", "a");

    for (int i = 0; i < items_count; i++)
    {
        Item item;
        printf("Enter name of item %d: ", i + 1);
        scanf("%s", item.name);
        printf("Enter quantity of item %d: ", i + 1);
        scanf("%d", &item.quantity);
        printf("Enter price of item %d: ", i + 1);
        scanf("%f", &item.price);

        fprintf(file, "%s,%d,%.2f\n", item.name, item.quantity, item.price);
    }

    fclose(file);
    printf("Items added successfully!\n");
    return 0;
}
int new_menu(){
    FILE *file = fopen("bakery/menu.csv", "w");
    fclose(file);
    add_items();
}
int admin_menu()
{
    while (1)
    {
        menu_file();
        printf("###################### ADMIN MENU ###################### \n");
        printf("1. Add Items \n");
        printf("2. Make New Menu Delete previous one\n");
        printf("3. Exit \n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            add_items();
        }
        else if (choice == 2)
        {
            new_menu();
        }
        else
        {
            break;
        }
    }
    return 0;
}
int admin_login()
{
    printf("######################### ADMIN ######################### \n");
    printf("Enter Username :");
    scanf("%40s", username);
    printf("Enter Password :");
    scanf("%40s", password);
    if (check_admin(username, password))
    {
        printf("Login Succesfully \n");
        admin_menu();
    }
    else
    {
        printf("Please try again later \n");
        printf("Username and Password are incorrect\n");
    }
}
int view_menu()
{
    FILE *file = fopen("bakery/menu.csv", "r");

    char line[MAX_LINE];
    printf("###################################################################### \n");
    printf("Item,Quantity,Price\n");
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
    printf("###################################################################### \n");
    return 0;
}
int buy_items()
{
    customer_file();
    time_date();
    id_generator();
    int items_count = 0;
    char costumer_name[30];
    float total = 0.0;
    printf("What is your name : ");
    while (getchar() != '\n')
        ;
    fgets(costumer_name, sizeof(costumer_name), stdin);
    size_t len = strlen(costumer_name);
    if (len > 0 && costumer_name[len - 1] == '\n')
    {
        costumer_name[len - 1] = '\0';
    }
    printf("How many items do you want to buy: ");
    scanf("%d", &items_count);

    FILE *c_file = fopen("bakery/customer.csv", "a");

    char filename[60];
    sprintf(filename, "bakery/%d.csv", customer_id);
    FILE *u_costumer = fopen(filename, "w");

    fprintf(c_file, "############################\n");
    fprintf(c_file, "Order Id Number, %d\n", customer_id);
    fprintf(c_file, "Purchased by , %s \nDate , %02d-%02d-%04d \nTime , %02d:%02d:%02d \n", costumer_name, current_date, current_month, current_year, current_hr, current_min, current_sec);
    fprintf(c_file, "Item,Quantity,Price \n");

    fprintf(u_costumer, "############################\n");
    fprintf(u_costumer, "Order Id Number, %d\n", customer_id);
    fprintf(u_costumer, "Purchased by , %s \nDate , %02d-%02d-%04d \nTime , %02d:%02d:%02d \n", costumer_name, current_date, current_month, current_year, current_hr, current_min, current_sec);
    fprintf(u_costumer, "Item,Quantity,Price \n");

    FILE *m_file = fopen("bakery/menu.csv", "r");
    for (int i = 0; i < items_count; i++)
    {
        Buy_Item item;
        printf("Enter name of item %d: ", i + 1);
        scanf("%s", item.name);
        printf("Enter quantity of item %d: ", i + 1);
        scanf("%d", &item.quantity);

        fseek(m_file, 0, SEEK_SET);
        char line[MAX_LINE];
        int found = 0;

        while (fgets(line, sizeof(line), m_file))
        {
            char *b_item = strtok(line, ",");
            char *b_quantati = strtok(NULL, ",");
            char *b_price = strtok(NULL, ",");

            if (b_item && strcmp(b_item, item.name) == 0 && b_price)
            {
                item.price = atof(b_price);
                found = 1;
                total = total + item.quantity * item.price;
                break;
            }
        }

        if (found)
        {
            fprintf(c_file, "%s,%d X ₹%.2f, ₹%.2f\n", item.name, item.quantity, item.price, item.price * item.quantity);
            fprintf(u_costumer, "%s,%d X ₹%.2f, ₹%.2f\n", item.name, item.quantity, item.price, item.price * item.quantity);
        }
        else
        {
            printf("Item %s is not in menu \n", item.name);
        }
    }
    fclose(m_file);
    fprintf(c_file, "Total Cost : ₹%.2f \n", total);
    fclose(c_file);
    FILE *id_file = fopen("bakery/id_alloted.csv", "a");
    fprintf(id_file, "%d \n", customer_id);
    fclose(id_file);
    printf("Your Order Id Number is: %d\n", customer_id);
    fprintf(u_costumer, "Total Cost : ₹%.2f \n", total);
    fclose(u_costumer);
}
int view_order_byid(const char *id_input)
{
    char filename[50];
    snprintf(filename, sizeof(filename), "bakery/%s.csv", id_input);

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Wrong id or id doesn't exist\n");
        return -1;
    }
    char line[MAX_LINE];
    printf("\033[0;31m"); //red
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
    printf("################################# \n");
    printf("\033[0;34m"); //default
    return 1;
}
int update_order()
{
    while (1)
    {
        printf("################################\n");
        printf("Enter Id No. :");
        scanf("%s", id_input);
        if (view_order_byid(id_input)==1)
        {
            printf("################################\n");
            printf("Take a Look at Your Order \nLets proceed to remake that from Starting \nWith New Order Id \n");
            printf("1. If you Agree \n");
            printf("2. Leave your order as it is \n");
            printf("Enter your Choice : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                buy_items();
                break;
            }
            else{
                break;
            }
        }else{
            break;
        }
    }
}
int costumer()
{
    while (1)
    {
        printf("######################### COSTUMER MENU ######################### \n");
        printf("1. View Menu \n");
        printf("2. Buy Items \n");
        printf("3. View Order \n");
        printf("4. Update Existing Order \n");
        printf("5. Exit \n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            view_menu();
        }
        else if (choice == 2)
        {
            buy_items();
        }
        else if (choice == 3)
        {
            printf("Enter Order Id to View : ");
            scanf("%s", id_input);
            view_order_byid(id_input);
        }
        else if (choice == 4)
        {
            update_order();
        }

        else
        {
            break;
        }
    }

    return 0;
}
int main_bakery()
{
    while (1)
    {
        printf("######################### BMS MENU ######################### \n");
        printf("1. Admin\n");
        printf("2. Costumer\n");
        printf("3. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            admin_login();
            break;
        case 2:
            costumer();
            break;
        default:
            printf("Wrong Try Again \n");
            break;
        }
        if (choice == 3)
        {
            break;
        }
    }
    return 0;
}