import pandas as pd
import matplotlib.pyplot as plt

# read CSV
signal = pd.read_csv("../visualization/signal.csv", header=None)
signal = signal.squeeze()  # pretvori DataFrame v Series

data = pd.read_csv("../visualization/data.csv", header=None, names=["frequency", "amplitude", "phase"])

sinusoids = pd.read_csv("../visualization/sinusoids.csv", header=None)

threshold = 1e-3
data.loc[data["amplitude"] < threshold, "phase"] = 0

fig, axs = plt.subplots(2, 2, figsize=(12, 6))

# the signal
axs[0, 0].plot(signal)
axs[0, 0].set_title("Signal")
axs[0, 0].set_xlabel("Sample index")
axs[0, 0].set_ylabel("Amplitude")
axs[0, 0].grid(True)

# sinusoids
colors = ["yellow", "orange", "red", "green", "cyan", "purple", "brown", "pink", "teal", "gray", "olive"]
for i in range(len(sinusoids)):
    axs[1, 0].plot(sinusoids.columns, sinusoids.iloc[i], color=colors[i % len(colors)], label=f"sin {i+1}")

axs[1, 0].set_title("Sinuosids")
axs[1, 0].set_xlabel("Sample index")
axs[1, 0].set_ylabel("Amplitude")
axs[1, 0].grid(True)
axs[1, 0].legend()

# draw amplitude spectrum
axs[0, 1].plot(data["frequency"], data["amplitude"])
axs[0, 1].set_xlabel("Frequency [Hz]")
axs[0, 1].set_ylabel("Amplitude")
axs[0, 1].set_title("FFT Amplitude Spectrum")
axs[0, 1].grid(True)

# draw phase spectrum
axs[1, 1].plot(data["frequency"], data["phase"])
axs[1, 1].set_xlabel("Frequency [Hz]")
axs[1, 1].set_ylabel("Phase [rad]")
axs[1, 1].set_title("FFT Phase Spectrum")
axs[1, 1].grid(True)

plt.tight_layout()
plt.show()
