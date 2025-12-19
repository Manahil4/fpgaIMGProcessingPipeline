from PIL import Image

img = Image.open("D:/ImgProcessingPipeline/img.png").convert("RGB")
img = img.resize((256, 256))

with open("D:/ImgProcessingPipeline/rgbImg.rgb", "wb") as f:
    f.write(img.tobytes())

print("RGB file generated")
