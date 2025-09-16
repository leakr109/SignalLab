import pandas as pd
import matplotlib.pyplot as plt

# preberi CSV
data = pd.read_csv("../visualization/data.csv", header=None, names=["frequency", "amplitude", "phase"])

threshold = 1e-3
data.loc[data["amplitude"] < threshold, "phase"] = 0

fig, (amp, phs) = plt.subplots(2, 1, figsize=(8, 6))

# draw amplitude spectrum
amp.plot(data["frequency"], data["amplitude"])
amp.set_xlabel("Frequency [Hz]")
amp.set_ylabel("Amplitude")
amp.set_title("FFT Amplitude Spectrum")
amp.grid(True)

# draw phase spectrum
phs.plot(data["frequency"], data["phase"])
phs.set_xlabel("Frequency [Hz]")
phs.set_ylabel("Phase [rad]")
phs.set_title("FFT Phase Spectrum")
phs.grid(True)

plt.tight_layout()
plt.show()
