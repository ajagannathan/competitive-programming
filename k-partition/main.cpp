#include"header.h"

void Partition(int *arr, int arr_size, int partitions)
{
    std::unordered_map<int, int> arr_map;
    int array_sum = 0;    
    for(size_t i = 0; i < arr_size; i++)
    {
        array_sum += arr[i];
        if(arr_map[arr[i]] == arr_map.end())        
            arr_map[arr[i]] = 1;
        else
            arr_map[arr[i]] += 1;        
    }
    if(array_sum % partitions != 0)
    {
        std::cout<<"partition failed!!";
        return;        
    }
    int partition_sum = array_sum/partitions;
    for(int k = 0; k<partitions; k++)
    {
        std::cout<<"Set "<<k<<": ";

    }

}

int main()
{
    int arr = {7,3,5,12,2,1,5,3,8,4,6,4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;



}