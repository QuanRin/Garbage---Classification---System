from project import app
from project.service.predict import predict, predict_2
from project.service.pre_train import pre_train
from project.service.classifier import classifier
from flask import request, make_response, jsonify
from PIL import Image
import numpy as np
import io
import base64


@app.route('/test', methods=['POST'])
def test():
    file = request.files['img']
    image_stream = io.BytesIO(file.read())

    img = Image.open(image_stream)
    image_array = np.array(img)

    if image_array.shape[2] == 4:
        image_array = image_array[:, :, :3]

    print(image_array.shape)
    resized_image = np.array(Image.fromarray(image_array).resize((224, 224)))
    pred = predict_2(img=np.array([resized_image]))
    return make_response(jsonify({"type": "guess", "class": pred}), 200)
