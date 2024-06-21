import subprocess
import time

def get_time(algo, data_type, data_size):
    start_time = time.time()
    subprocess.run(f"./{algo} {data_type}{data_size}.txt", shell=True, check=True, cwd="./sort")
    end_time = time.time()
    return end_time - start_time

def get_average(algo, data_type, data_size, sample_size):
    samples = []
    total_time = 0
    for i in range(sample_size):
        time = get_time(algo, data_type, data_size)
        total_time += time
        samples.append(float(str(round(time, 5))[:5]))

        average = round(total_time / sample_size, 3)

    data = {
        "average": average,
        "samples": samples
    }

    return data


def main():
    algos = ["sort1", "sort2", "sort3"]
    data_types = ["sorted", "reversed", "random"]
    data_sizes = [5_000, 10_000, 50_000]

    data = dict()

    for algo in algos:
        data[algo] = dict()
        for data_type in data_types:
            for data_size in data_sizes:
                data[algo][f"{data_type}{data_size}"] = get_average(algo, data_type, data_size, 10)

    print(data)

main()
