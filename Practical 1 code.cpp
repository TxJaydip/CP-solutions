#include <iostream>
#include <vector>
#include <mpi.h>
#define N 5
enum PhilosopherState
{
    THINKING,
    HUNGRY,
    EATING
};
int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Win win;
    int forks[N];
    MPI_Win_create(forks, N * sizeof(int), sizeof(int), MPI_INFO_NULL,
                   MPI_COMM_WORLD, &win);
    for (int i = 0; i < N; i++)
    {
        forks[i] = 1;
    }
    auto pick_forks = [&](int left, int right)
    {
        MPI_Win_lock(MPI_LOCK_EXCLUSIVE, rank, 0, win);
        forks[left] = 0;
        forks[right] = 0;
        MPI_Win_unlock(rank, win);
    };
    auto release_forks = [&](int left, int right)
    {
        MPI_Win_lock(MPI_LOCK_EXCLUSIVE, rank, 0, win);
        forks[left] = 1;
        forks[right] = 1;
        MPI_Win_unlock(rank, win);
    };
    for (int i = 0; i < N; i++)
    {
        int left = i;
        int right = (i + 1) % N;
        if (rank == i)
        {
            int thinking_time = rank + 1;
            int eating_time = rank + 1;
            for (int j = 0; j < 3; j++)
            {
                std::cout << "Philosopher " << rank << " is thinking." << std::endl;
                MPI_Barrier(MPI_COMM_WORLD);
                std::cout << "Philosopher " << rank << " is hungry." << std::endl;
                MPI_Barrier(MPI_COMM_WORLD);
                pick_forks(left, right);
                std::cout << "Philosopher " << rank << " is eating." << std::endl;
                MPI_Barrier(MPI_COMM_WORLD);
                release_forks(left, right);
            }
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                MPI_Barrier(MPI_COMM_WORLD);
                MPI_Barrier(MPI_COMM_WORLD);
                MPI_Barrier(MPI_COMM_WORLD);
                MPI_Barrier(MPI_COMM_WORLD);
            }
        }
    }
    MPI_Win_free(&win);
    MPI_Finalize();
    return 0;
}