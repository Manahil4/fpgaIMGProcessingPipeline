from PIL import Image

def convert_gray_to_png(raw_file, output_file, width=254, height=254):
    try:
        with open(raw_file, 'rb') as f:
            raw_data = f.read()
            
        # Check if the file size matches our expected dimensions
        expected_size = width * height
        if len(raw_data) != expected_size:
            print(f"Warning: File size {len(raw_data)} does not match {width}x{height} ({expected_size})")
        
        # 'L' mode is 8-bit pixels, black and white
        img = Image.frombytes('L', (width, height), raw_data)
        img.save(output_file)
        print(f"✅ Successfully converted {raw_file} to {output_file}")
    except Exception as e:
        print(f"❌ Failed to convert {raw_file}: {e}")

# IMPORTANT: Match these to your actual output size!
convert_gray_to_png('./grayImg.gray', './result_grayscale.png', 256, 256) # Grayscale usually keeps full size
convert_gray_to_png('./blurred.gray', './result_blurred.png', 256, 256)   # Filtered loses 2 pixels
convert_gray_to_png('./edges.gray', './result_edges.png', 256, 256)       # Filtered loses 2 pixels