import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, confusion_matrix

# Load EMNIST dataset
(x_train, y_train), (x_test, y_test) = keras.datasets.mnist.load_data()

# Display a sample image
some_digit = x_train[810]
some_digit_image = some_digit.reshape(28, 28)
plt.imshow(some_digit_image, cmap="binary")
plt.axis("off")
plt.show()

print("Size of the dataset:", len(x_train) + len(x_test))
print("Number of elements in the training set:", len(x_train))
print("Number of elements in the test set:", len(x_test))

# Preprocess the dataset for traditional ML models
x_train_flat = x_train.reshape(-1, 28 * 28).astype("float32") / 255.0
x_test_flat = x_test.reshape(-1, 28 * 28).astype("float32") / 255.0

x_train_ml, _, y_train_ml, _ = train_test_split(x_train_flat, y_train, train_size=10000, stratify=y_train, random_state=42)
x_test_ml, _, y_test_ml, _ = train_test_split(x_test_flat, y_test, train_size=2000, stratify=y_test, random_state=42)

# ===================== K-Nearest Neighbors =====================
knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(x_train_ml, y_train_ml)
y_pred_knn = knn.predict(x_test_ml)
accuracy_knn = accuracy_score(y_test_ml, y_pred_knn)
print(f"K-NN Test Accuracy: {accuracy_knn:.4f}")

cm_knn = confusion_matrix(y_test_ml, y_pred_knn)
plt.figure(figsize=(10, 8))
sns.heatmap(cm_knn, annot=True, fmt="d", cmap="Blues")
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Confusion Matrix (K-NN)")
plt.show()

# ===================== Support Vector Machine =====================
svm = SVC(kernel='linear', random_state=42)
svm.fit(x_train_ml, y_train_ml)
y_pred_svm = svm.predict(x_test_ml)
accuracy_svm = accuracy_score(y_test_ml, y_pred_svm)
print(f"SVM Test Accuracy: {accuracy_svm:.4f}")

cm_svm = confusion_matrix(y_test_ml, y_pred_svm)
plt.figure(figsize=(10, 8))
sns.heatmap(cm_svm, annot=True, fmt="d", cmap="Blues")
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Confusion Matrix (SVM)")
plt.show()

# ===================== Logistic Regression =====================
logreg = LogisticRegression(max_iter=1000)
logreg.fit(x_train_ml, y_train_ml)
y_pred_logreg = logreg.predict(x_test_ml)
accuracy_logreg = accuracy_score(y_test_ml, y_pred_logreg)
print(f"Logistic Regression Test Accuracy: {accuracy_logreg:.4f}")

cm_logreg = confusion_matrix(y_test_ml, y_pred_logreg)
plt.figure(figsize=(10, 8))
sns.heatmap(cm_logreg, annot=True, fmt="d", cmap="Blues")
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Confusion Matrix (Logistic Regression)")
plt.show()

# ===================== Decision Tree =====================
dt_classifier = DecisionTreeClassifier()
dt_classifier.fit(x_train_ml, y_train_ml)
y_pred_dt = dt_classifier.predict(x_test_ml)
accuracy_dt = accuracy_score(y_test_ml, y_pred_dt)
print(f"Decision Tree Test Accuracy: {accuracy_dt:.4f}")

cm_dt = confusion_matrix(y_test_ml, y_pred_dt)
plt.figure(figsize=(10, 8))
sns.heatmap(cm_dt, annot=True, fmt="d", cmap="Blues")
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Confusion Matrix (Decision Tree)")
plt.show()

# ===================== Convolutional Neural Network =====================
x_train_cnn = x_train.reshape(-1, 28, 28, 1).astype("float32") / 255.0
x_test_cnn = x_test.reshape(-1, 28, 28, 1).astype("float32") / 255.0

model = keras.Sequential([
    keras.Input(shape=(28, 28, 1)),
    layers.Conv2D(32, kernel_size=(3, 3), activation="relu"),
    layers.MaxPooling2D(pool_size=(2, 2)),
    layers.Conv2D(64, kernel_size=(3, 3), activation="relu"),
    layers.MaxPooling2D(pool_size=(2, 2)),
    layers.Flatten(),
    layers.Dropout(0.5),
    layers.Dense(10, activation="softmax"),
])

model.compile(loss="sparse_categorical_crossentropy", optimizer="adam", metrics=["accuracy"])
model.fit(x_train_cnn, y_train, batch_size=128, epochs=10, validation_split=0.1)

loss_cnn, accuracy_cnn = model.evaluate(x_test_cnn, y_test, verbose=0)
print(f"CNN Test Loss: {loss_cnn:.4f}")
print(f"CNN Test Accuracy: {accuracy_cnn:.4f}")

# Visualize CNN Confusion Matrix
y_pred_cnn = np.argmax(model.predict(x_test_cnn), axis=1)
cm_cnn = confusion_matrix(y_test, y_pred_cnn)
plt.figure(figsize=(10, 8))
sns.heatmap(cm_cnn, annot=True, fmt="d", cmap="Blues")
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Confusion Matrix (CNN)")
plt.show()
