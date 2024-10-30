# Use an official lightweight image as the base image
FROM debian:bullseye-slim

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && \
    apt-get install -y socat && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the binary, serve.sh script, key file, and flags folder
COPY breakroom_adventure ./main
COPY serve.sh ./serve.sh
COPY key ./key
COPY flags/ ./flags/

# Make sure the binary, script, and key file are executable/readable
RUN chmod +x ./main ./serve.sh && \
    chmod 600 ./key

# Expose the port
EXPOSE 12345

# Start the service
CMD ["./serve.sh"]
