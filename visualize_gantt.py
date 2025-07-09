import matplotlib.pyplot as plt
import matplotlib.animation as animation
import csv

# Load process data
processes = []
with open("process_log.csv", newline='') as f:
    reader = csv.DictReader(f)
    for row in reader:
        processes.append({
            'pid': int(row['PID']),
            'start': int(row['Start']),
            'duration': int(row['Burst'])
        })

# Use a set of distinct tab colors
colors = ['tab:blue', 'tab:orange', 'tab:green', 'tab:red', 'tab:purple', 'tab:brown', 'tab:pink', 'tab:gray', 'tab:olive', 'tab:cyan']

fig, gnt = plt.subplots()
gnt.set_xlabel('Time')
gnt.set_ylabel('Processes')
gnt.set_title('Gantt Chart with Unique Colors')
gnt.grid(True)

yticks = []
ytlabels = []

# Draw colored bars one by one
def animate(i):
    if i < len(processes):
        p = processes[i]
        y = 10 + i * 10
        yticks.append(y + 5)
        ytlabels.append(f"P{p['pid']}")
        gnt.set_yticks(yticks)
        gnt.set_yticklabels(ytlabels)

        color = colors[i % len(colors)]  # Safe wrap if >10 processes
        gnt.broken_barh([(p['start'], p['duration'])], (y, 9), facecolors=color)

ani = animation.FuncAnimation(fig, animate, frames=len(processes), interval=1000, repeat=False)
plt.show()