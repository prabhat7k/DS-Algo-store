import numpy as np

def matrix_multiply(A, B):
    """Multiply two matrices using NumPy."""
    if A.shape[1] != B.shape[0]:
        raise ValueError("Matrix dimensions are not compatible for multiplication.")
    return np.dot(A, B)

if __name__ == "__main__":
    A = np.array([[1, 2], [3, 4]])
    B = np.array([[5, 6], [7, 8]])
    print("Matrix A × B =\n", matrix_multiply(A, B))
