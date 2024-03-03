import numpy as np
import keras
def zero_center_normalize_image(image):
    mean = np.mean(image)
    std_dev = np.std(image)
    normalized_image = (image - mean) / std_dev
    return 2 * (normalized_image - np.min(normalized_image)) / np.ptp(normalized_image) - 1

pre = None

def load_pre_train():
    global pre
    if not pre:
        print("true")
        pre = keras.models.load_model("pre_train.keras")
    return pre

def pre_train(img):
    pre = load_pre_train()
    normalized_img = zero_center_normalize_image(np.array(img))
    fts = pre.predict(np.array([normalized_img]))
    return fts.reshape(fts.shape[0],-1)