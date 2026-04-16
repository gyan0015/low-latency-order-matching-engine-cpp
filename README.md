# ⚡ Order Matching Engine (C++)

A simplified **Limit Order Book Matching Engine** implemented in C++17.  
This project simulates the **core logic of an exchange**: handling limit/market orders, order cancellations, and matching trades based on **price-time priority**.

---

## 🚀 Features
- **Limit Orders**: Add buy/sell limit orders to the order book.
- **Market Orders**: Immediately executed against the best available prices.
- **Order Cancellation**: Cancel existing orders by ID (lazy deletion).
- **Price-Time Priority**: Orders are matched by best price, then earliest arrival.
- **Order Book View**: Print top N bid/ask levels.
- **Stress Testing**: Handles up to **1,000,000 orders in <200ms** on a laptop.

---

## 📊 Performance Benchmark
```text
Machine: MacBook Pro M1, 16GB RAM
Command: ./matching

Running stress test with 1,000,000 orders...
Processed 1,000,000 orders in 152 ms
```
## 🛠️ Project Structure
OrderMatchingEngine/
│── src/
│   ├── main.cpp              # Entry point (demo + stress test)
│   ├── order.h               # Order struct
│   ├── orderbook.h           # OrderBook class (declaration)
│   ├── matching_engine.cpp   # OrderBook implementation
│
│── tests/
│   └── test_orderbook.cpp    # (Optional) Unit tests
│
│── Makefile                  # Build automation
│── README.md                 # Project documentation
▶️ Getting Started

Prerequisites
	•	C++17 compatible compiler (g++, clang++)
	•	Make (for build automation)

Build & Run
# Clone repo
git clone https://github.com/<your-username>/OrderMatchingEngine.git
cd OrderMatchingEngine

# Build project
make

# Run executable
```text
./matching
📖 Example Output
----- Order Book (Top 5) -----
Bids:
  101 x 10 (ID 1)
Asks:
  102 x 5 (ID 2)
------------------------------
Running stress test with 1000000 orders...
Processed 1000000 orders in 152 ms
```

🔮 Future Improvements
	•	Multi-asset support (BTC, ETH, AAPL, etc.)
	•	Advanced order types (Stop-loss, Iceberg, Fill-or-Kill)
	•	Multi-threaded matching engine
	•	Persistent trade log (to file or database)
	•	API layer (REST/WebSocket) for live trading simulation

⸻

👨‍💻 Author
	•	Xiaochuan Li – MSc Financial Engineering
	•	LinkedIn
	•	GitHub

⸻

📜 License

This project is licensed under the MIT License – see the LICENSE file for details.
