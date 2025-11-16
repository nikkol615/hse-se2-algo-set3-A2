import pandas as pd
import matplotlib.pyplot as plt

def plot_comparison(merge_file, insertion_merge_file, output_image):
    try:
        merge_data = pd.read_csv(merge_file)
        insertion_merge_data = pd.read_csv(insertion_merge_file)
    except FileNotFoundError as e:
        print(f"Error: {e}. Please make sure the CSV files are in the correct directory.")
        return

    plt.figure(figsize=(14, 8))

    plt.plot(merge_data['Elements'], merge_data['Random'], label='Merge Sort - Random', linestyle='-')
    plt.plot(merge_data['Elements'], merge_data['Hard'], label='Merge Sort - Hard', linestyle='-')
    plt.plot(merge_data['Elements'], merge_data['Easy'], label='Merge Sort - Easy', linestyle='-')

    plt.plot(insertion_merge_data['Elements'], insertion_merge_data['Random'], label='Insertion-Merge Sort - Random', linestyle='--')
    plt.plot(insertion_merge_data['Elements'], insertion_merge_data['Hard'], label='Insertion-Merge Sort - Hard', linestyle='--')
    plt.plot(insertion_merge_data['Elements'], insertion_merge_data['Easy'], label='Insertion-Merge Sort - Easy', linestyle='--')

    plt.title('Comparison of Merge Sort and Insertion-Merge Sort')
    plt.xlabel('Number of Elements')
    plt.ylabel('Time (microseconds)')
    plt.legend()
    plt.grid(True)
    
    plt.savefig(output_image)
    print(f"Graph saved to {output_image}")

if __name__ == '__main__':
    plot_comparison('mergeResults.csv', 'insertionMergeResults.csv', 'sort_comparison.png')
