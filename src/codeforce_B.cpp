#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long files_count;
    cin >> files_count; // кол-во файлов
    long long modules_count;
    cin >> modules_count; // кол-во модулей в видеокурсе

    vector<long long> file_processing_time; // время, необходимое а обработку каждого файла
    long long current_file;                 // текущий файл
    for (long long i = 0; i < files_count; i++)
    {
        cin >> current_file;
        file_processing_time.push_back(current_file);
    }

    vector<long long> module_learning_time; // время, необходимое для просмотра каждого модуля
    long long current_module;               // текущий модуль

    for (long long i = 0; i < modules_count; i++)
    {
        cin >> current_module;
        module_learning_time.push_back(current_module);
    }

    long long file_processing_done_time = 0; // время заверения работы обработки файла
    long long module_learning_done_time = 0; // время завершения просмотра последнего модуля

    long long file_index = 0;
    long long module_index = 0;

    while (file_index < files_count && module_index < modules_count)
    {
        if (module_learning_time[module_index] <= 0)
        {
            module_index++;
            if (module_index >= modules_count)
            {
                break;
            }
            if (file_processing_time[file_index] <= module_learning_time[module_index] / 2 && file_processing_time[file_index] > 0)
            {
                file_processing_done_time += file_processing_time[file_index];
                module_learning_done_time += file_processing_time[file_index];
                file_processing_time[file_index] = 0;
            }
        }

        if (file_processing_time[file_index] <= 0)
        {
            file_index++;
            if (file_index >= files_count)
            {
                break;
            }
        }

        if (file_processing_time[file_index] <= module_learning_time[module_index] && file_processing_time[file_index] > 0 && module_learning_time[module_index] > 0)
        {
            if (file_index == files_count - 1)
            {
                file_processing_done_time += file_processing_time[file_index];
                module_learning_done_time += module_learning_time[module_index];
                file_processing_time[file_index] = 0;
                module_learning_time[module_index] = 0;
            }
            else
            {
                file_processing_done_time += module_learning_time[module_index];
                module_learning_done_time += module_learning_time[module_index];
                file_processing_time[file_index] = 0;
                module_learning_time[module_index] = 0;
            }
        }
        else if (file_processing_time[file_index] > 0 && module_learning_time[module_index] > 0)
        {
            file_processing_time[file_index] -= module_learning_time[module_index];
            file_processing_done_time += module_learning_time[module_index];
            module_learning_done_time += module_learning_time[module_index];
            module_learning_time[module_index] = 0;
        }
    }

    if (file_index >= files_count)
    {
        while (module_index < modules_count)
        {
            module_learning_done_time += module_learning_time[module_index];
            module_index++;
        }
    }

    else if (module_index >= modules_count)
    {
        while (file_index < files_count)
        {
            file_processing_done_time += file_processing_time[file_index];
            file_index++;
        }
    }

    cout << module_learning_done_time << endl;
    cout << file_processing_done_time << endl;
}